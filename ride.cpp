/*
  ID:jacky.l1
  LANG: C++
  PROG: ride
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

const int size = 11;
const int mod = 47;

int get_mod(char *str)
{
    char *ch = str;
    int ret = 1;
    while(*ch)
    {
        ret *= (*ch - 'A' + 1);
        ch++;
    }
    return ret % mod;
}

int main()
{
    char ll[size], rr[size];
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    scanf("%s%s", ll, rr);
    if(get_mod(ll) == get_mod(rr))
    {
        printf("GO\n");
    }
    else
    {
        printf("STAY\n");
    }
    exit(0);
}
