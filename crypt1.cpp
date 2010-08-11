/*
LANG:  C++
ID: jacky.l1
PROB:crypt1
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

const int size = 10;
int sets[size];
bool bits[size];
int n;

bool test(int A, int len)
{
	char buf[11];
	memset(buf, 0, sizeof(buf));
	sprintf(buf, "%d", A);
	if(strlen(buf) != len)
		return false;
	for(int j = 0; j < len; j++)
		if(!bits[buf[j] - '0'])
			return false;
	return true;
}

bool judge(int i, int j, int k, int m, int p)
{
	int A = i * 100 + j * 10 + k;
	int B = 10 * m + p;
	int C = A * B;
	int D = A * m;
	if(!test(D, 3))
		return false;
	D = A * p;
	if(!test(D, 3))
		return false;
	if(!test(C, 4))
		return false;
	//fprintf(stderr, "%d * %d = %d\n", A, B, C);
	return true;
}

int main()
{
	int i, j, k, m, p, ans = 0;
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);
	scanf("%d", &n);
	for(j = 0; j < n; j++)
	{
		scanf("%d", &sets[j]);
		bits[sets[j]] = true;
	}
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			for(k = 0; k < n; k++)
			{
				for(m = 0; m < n; m++)
				{
					for(p = 0; p < n; p++)
					{
						if(judge(sets[i], sets[j], sets[k], sets[m], sets[p]))
							ans++;
					}
				}
			}
		}
	}
	printf("%d\n", ans);
    return 0;
}

