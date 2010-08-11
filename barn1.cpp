/*
LANG:  C++
ID: jacky.l1
PROB:barn1
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
const int size = 201;
int input[size];
pair<int, int> vecs[size];
int M, S, C;

int main()
{
	int j, k, n, ans, key;
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);
	scanf("%d%d%d", &M, &S, &C);
	for(j = 0; j < C; j++)
	{
		scanf("%d", &input[j]);
	}
	sort(input, input + C, less<int>());
	vecs[0].first = vecs[0].second = input[0];
	for(j = 1, k = 0; j < C; j++)
	{
		if(input[j] - vecs[k].second == 1)
		{
			vecs[k].second = input[j];
		}
		else
		{
			vecs[++k].first = input[j];
			vecs[k].second = input[j];
		}
	}
	/*
	for(j = 0; j <= k; j++)
	{
		fprintf(stderr, "(%d, %d) ", vecs[j].first, vecs[j].second);
	}
	fprintf(stderr, "\n");
	*/
	n = k;
	while(n >= M)
	{
		ans = size, key = -1;
		for(j = 1; j <= n; j++)
		{
			if(vecs[j].first - vecs[j - 1].second + 1 < ans)
			{
				ans = vecs[j].first - vecs[j - 1].second + 1;
				key = j;
			}
		}
		vecs[key - 1].second = vecs[key].second;
		for(int i = key; i <= n - 1; i++)
		{
			vecs[i] = vecs[i + 1];
		}
		n--;
	}
	ans = 0;	
	for(j = 0; j <= n; j++)
	{
		//fprintf(stderr, "(%d, %d) ", vecs[j].first, vecs[j].second);
		ans += vecs[j].second - vecs[j].first + 1;
	}
	//fprintf(stderr, "\n");
	printf("%d\n", ans);
	//fprintf(stderr, "%d\n", ans);
    return 0;
}
