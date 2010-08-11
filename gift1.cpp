/*
    ID: jacky.l1
    LANG: C++
    PROG: gift1
 */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

const int size = 11;
const int N = 15;
char grp[size][N];
int gift[size], ans[size];

int find_idx(char *str, int n)
{
    for(int j = 0; j < n; j++)
    {
        if(!strcmp(str, grp[j]))
            return j;
    }
    return -1;
}

int main()
{
    int n, j, k;
    char name[size];
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);
    scanf("%d", &n);
    for(j = 0; j < n; j++)
    {
        scanf("%s", grp[j]);
    }
    for(j = 0; j < n; j++)
    {
       scanf("%s", name); 
       int fr = find_idx(name, n), to, nto;
       scanf("%d%d", &gift[fr], &nto);
       for(k = 0; k < nto; k++)
       {
           scanf("%s", name);
           to = find_idx(name, n);
           ans[to] += gift[fr] / nto;
       }
       if(nto)
            ans[fr] += gift[fr] % nto;
    }
    for(j = 0; j < n; j++)
    {
        printf("%s %d\n", grp[j], ans[j] - gift[j]);
        //fprintf(stderr, "%s %d\n", grp[j], ans[j] - gift[j]);
    }
    exit(0);
}
