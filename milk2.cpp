/*
  ID:jacky.l1
  LANG: C++
  PROG: milk2
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef struct item{
    int sta, end;
}item;

const int size = 5007;
item before[size];
item after[size];

struct cmp{
    bool operator()(const item& lhs, const item& rhs)
    {
        if(lhs.sta == rhs.sta)
        {
            return lhs.end > rhs.end;
        }
        else
            return lhs.sta < rhs.sta;
    }
};

int main()
{
    int j, N, k, p, max_c, max_p;
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);
    scanf("%d", &N);
    for(j = 0; j < N; j++)
    {
        scanf("%d%d", &before[j].sta, &before[j].end);
    }
    std::sort(before, before + N, cmp());
    /*
    for(j = 0; j < N; j++)
    {
        fprintf(stderr, "%d => %d\n", before[j].sta, before[j].end);
    }
    */
    after[0] = before[0];
    j = 0, k = 1;
    while(k < N)
    {
        if(before[k].sta >= after[j].sta && before[k].end <= after[j].end)
            k++;
        else if(before[k].sta <= after[j].end && before[k].end >= after[j].end){
            after[j].end = before[k].end;
            k++;
        }
        else if(before[k].sta > after[j].end)
        {
            j++;
            after[j] = before[k];
            k++;
        }
    }
    j++;
    /*
    for(k = 0; k < j; k++)
    {
        fprintf(stderr, "%d => %d\n", after[k].sta, after[k].end);
    }
    */
    max_c = after[0].end - after[0].sta;
    for(k = 1, max_p = 0; k < j; k++)
    {
        max_c = max(max_c, (after[k].end - after[k].sta));
        max_p = max(max_p, (after[k].sta - after[k - 1].end));
    }
    printf("%d %d\n", max_c, max_p);
    //fprintf(stderr, "%d %d\n", max_c, max_p);
    return 0;
}
