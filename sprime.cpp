/*
LANG:  C++
ID: jacky.l1
PROB:sprime
*/
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;
const int size = 100000;
bool prime[size];

void sieve()
{
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for(int j = 2; j < size; j++)
	{
		if(!prime[j])continue;
		for(int k = 2; k * j < size; k++)
			prime[k * j] = false;
	}
}

bool is_prime(int n)
{
	if(n < size)return prime[n];
	int t = (int)sqrt(n);
	for(int j = 2; j <= t; j++)
		if(n % j == 0)return false;
	return true;
}

bool judge(int n)
{
	if(!is_prime(n))return false;
	while(n)
	{
		if(is_prime(n))
			n /= 10;
		else
			break;
	}
	if(n == 0)return true;
	return false;
}

int nums[6] = {1, 2, 3, 5, 7, 9};
int prod[8] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

void dfs(int cur, int n)
{
	if(n == 0)
	{
		if(is_prime(cur))
			printf("%d\n", cur);
		return;
	}
	if(cur && !is_prime(cur))
		return;
	for(int j = 0; j < 6; j++)
	{
		dfs(cur * 10 + nums[j], n - 1);
	}
}

void get_ans(int n)
{
	sieve();
	dfs(0, n);
}

int main()
{
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);
	int n;
	scanf("%d", &n);
	get_ans(n);
    return 0;
}
