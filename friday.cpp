/*
    ID: jacky.l1
    LANG: C++
    PROG: friday
*/
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

int days[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                   {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

bool is_leap(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int freq[7];

void calc(int n)
{
    int y, m, p = 2;
    for(y = 1900; y < 1900 + n; y++)
    {
        bool leap = is_leap(y);
        for(m = 1; m <= 12; m++)
        {
            freq[(p + 12) % 7]++;
            p += days[leap][m];
        }
    }
}

int main()
{
    int N;
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);
    scanf("%d", &N);
    calc(N);
    for(int j = 0; j < 7; j++)
    {
        printf("%d", freq[j]);
        if(j == 6){
            printf("\n");
        }
        else{
            printf(" ");
        }
    }
    return 0;
}

