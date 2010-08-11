/*
    ID: jacky.l1
    LANG: C++
    PROG: palsquare
 */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

bool  palindrome(char *str)
{
    bool ret = true;
    int len = strlen(str);
    for(int j = 0; j < len - 1 - j; j++)
    {
        if(str[j] != str[len - 1 - j])
            return false;
    }
    return true;
}

void reverse(char *str)
{
    int j, len = strlen(str);
    for(j = 0; j < len - 1 - j; j++)
        swap(str[j], str[len - 1 - j]);
}

void int2base(int n, int base, char *str)
{
    int j, len = 0;
    j = n;
    while(j){
        str[len++] = "0123456789ABCDEFGHIJK"[j % base];
        j /= base;
    }
    str[len] = '\0';
}

char str[1024], cur[1024];
int main()
{
    int j, k, base;
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);
    scanf("%d", &base);
    memset(str, 0, sizeof(str));
    for(j = 1; j <= 300; j++)
    {
        int2base(j, base, cur);
        reverse(cur);
        int2base(j * j, base, str);
        if(palindrome(str)){
            printf("%s %s\n", cur, str);
            //fprintf(stderr, "%s %s\n", cur, str);
        }
    }
    return 0;
}
