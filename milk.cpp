/*
LANG:  C++
ID: jacky.l1
PROB:milk
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

const int size = 5011;
pair<int, int> cows[size];

struct cmp{
	bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs)
	{
		return lhs.first < rhs.first;
	}
};

int main()
{
	int j, N, M, ans;
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);
	scanf("%d%d", &N, &M);
	for(j = 0; j < M; j++)
	{
		scanf("%d%d", &cows[j].first, &cows[j].second);
	}
	sort(cows, cows + M, cmp());
	for(j = 0, ans = 0; j < M; j++)
	{
		int amount = min(N, cows[j].second);
		ans += amount * cows[j].first;
		N -= amount;
		if(N == 0)
			break;
	}
	printf("%d\n", ans);
    return 0;
}

