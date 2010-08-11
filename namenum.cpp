/*
LANG:  C++
ID: jacky.l1
PROB:namenum
*/
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int size = 26;
const int wsz = 101;

typedef struct trie{
    struct trie *child[26];
    bool flag;
    char *str;
}trie_t;

char maps[8][3] = {{'A', 'B', 'C'}, 
                   {'D', 'E', 'F'},
                   {'G', 'H', 'I'},
                   {'J', 'K', 'L'},
                   {'M', 'N', 'O'},
                   {'P', 'R', 'S'},
                   {'T', 'U', 'V'},
                   {'W', 'X', 'Y'}};

trie_t* trie_init()
{
    trie_t * trie_root = (trie_t*)malloc(sizeof(trie_t));
    return trie_root;
}

trie_t* trie_get()
{
    return (trie_t*)calloc(1, sizeof(trie_t));
}

void trie_insert(trie_t **trie_root, const char *str)
{
    trie_t * cur = *trie_root;
    char *ch = const_cast<char*>(str);
    while(*ch)
    {
        if(cur->child[*ch - 'A'] == NULL)
        {
            cur->child[*ch - 'A'] = trie_get();
        }
        cur = cur->child[*ch - 'A'];
        ch++;
    }
    cur->flag = true;
    cur->str = (char*)malloc(strlen(str) + 1);
    strcpy(cur->str, str);
}

char* trie_find(trie_t **trie_root, const char *str)
{
    trie_t * cur = *trie_root;
    char *ch = const_cast<char*>(str);
    while(*ch)
    {
        if(cur->child[*ch - 'A'] == NULL)
            return false;
        cur = cur->child[*ch - 'A'];
        ch++;
    }
    if(cur->flag)
        return cur->str;
    else
        return NULL;
}

bool flag = false;

void dfs(const char *str, trie_t* cur)
{
    char *ch = const_cast<char*>(str);
    if(*ch == 0)
    {
        if(cur->flag){
            printf("%s\n", cur->str);
        }
        flag = true;
        return;
    }
    else{
        int idx = *ch - '2';
        ch++;
        for(int j = 0; j < 3; j++)
        {
            if(cur->child[maps[idx][j]  - 'A'] != NULL)
                dfs(ch, cur->child[maps[idx][j] - 'A']);
        }
    }
}

int main()
{
    char word[wsz];
    FILE * fp = fopen("dict.txt", "r");
    trie_t *cur = trie_init();
    memset(word, 0, sizeof(word));
    while(fscanf(fp, "%s", word) != EOF)
    {
        trie_insert(&cur, word);
    }
    fclose(fp);
    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);
    scanf("%s", word);
    dfs(word, cur);
    if(!flag)
        printf("NONE\n");
    return 0;
}
