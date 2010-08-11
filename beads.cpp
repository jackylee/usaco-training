/*
    ID: jacky.l1
    LANG: C++
    PROG: beads
 */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

const int size = 351;
char neck[size];
//dp(i, 0), dp(i, 1)

int calc(int j, int N)
{
    int i = j,  cnt = 0;
    bool pre = false;
    char last = neck[i];
    while(true)
    {
        if(last == 'w' && neck[i] != last)
        {
            last = neck[i];            
            cnt++;
        }
        else if(neck[i] == 'w')
        {
            cnt++;
        }
        else if(neck[i] == last)
        {
            cnt++;
        }
        else if(neck[i] != last && !pre)
        {
            pre = true;
            last = neck[i];
            cnt++;
        }
        else if(neck[i] != last && pre)
        {
            break;
        }
        i = (i + 1) % N;
        if(i == j)break;
    }
    //printf("%d=>%d\n", i, j);
    return cnt;
}

int main()
{
    int j, k, N, ans = 2;
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
    scanf("%d", &N);
    scanf("%s", neck);
    for(j = 0; j < N; j++)
    {
        ans = max(ans, calc(j,  N));
    }
    printf("%d\n", ans);
    //fprintf(stderr, "%d\n", ans);
    return 0;
}


