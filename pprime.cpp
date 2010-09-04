/*
LANG:  C++
ID: jacky.l1
PROB:pprime
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

const int size = 100000001;

int get_bits(int n)
{
	int cnt = 0;
	while(n)
	{
		n /= 10;
		cnt++;
	}
	return cnt;
}

bool is_prime(int n)
{
	int t = (int)sqrt(n);
	for(int j = 2; j <= t; j++)
		if(n % j == 0)
			return false;
	return true;
}

typedef void (*func)(int, int);

void gen_one(int s, int e)
{
	for(int j = 2; j <= 9; j++)
		if(is_prime(j) && s <= j && j <= e)
			printf("%d\n", j);
}

void gen_two(int s, int e)
{
	for(int j = 1; j <= 9; j += 2)
	{
		int d = j * 10 + j;
		if(s <= d && d <= e && is_prime(d))
			printf("%d\n", j * 10 + j);
	}
}

void gen_three(int s, int e)
{
	for(int j = 1; j <= 9; j += 2)
	{
		for(int k = 0; k <= 9; k++)
		{
			int d = j * 100 + k * 10 + j;
			if(s <= d && d <= e && is_prime(d))
				printf("%d\n", d);
		}
	}
}

void gen_four(int s, int e)
{
	for(int j = 1; j <= 9; j += 2)
	{
		for(int k = 0; k <= 9; k++)
		{
			int d = j * 1000 + 100 * k + 10 * k + j;
			if(s <= d && d <= e && is_prime(d))
				printf("%d\n", d);
		}
	}
}

void gen_five(int s, int e)
{
	for(int j = 1; j <= 9; j += 2)
	{
		for(int k = 0; k <= 9; k++)
		{
			for(int m = 0; m <= 9; m++)
			{
				int d = j * 10000 + k * 1000 + m * 100 + k * 10 + j;
				if(s <= d && d <= e && is_prime(d))
					printf("%d\n", d);
			}
		}
	}
}

void gen_six(int s, int e)
{
	for(int j = 1; j <= 9; j += 2)
	{
		for(int k = 0; k <= 9; k++)
		{
			for(int m = 0; m <= 9; m++)
			{
				int d = j * 100000 + k * 10000 + m * 1000 + m * 100 + k * 10 + j;
				if(s <= d && d <= e && is_prime(d))
					printf("%d\n", d);
			}
		}
	}
}

void gen_seven(int s, int e)
{
	for(int j = 1; j <= 9; j += 2)
	{
		for(int k = 0; k <= 9; k++)
		{
			for(int m = 0; m <= 9; m++)
			{
				for(int n = 0; n <= 9; n++)
				{
					int d = j * 1000000 + k * 100000 + m * 10000 + n * 1000 + m * 100 + k * 10 + j;
					if(s <= d && d <= e && is_prime(d))
						printf("%d\n", d);
				}
			}
		}
	}
}

void gen_eight(int s, int e)
{
	for(int j = 1; j <= 9; j += 2)
	{
		for(int k = 0; k <= 9; k++)
		{
			for(int m = 0; m <= 9; m++)
			{
				for(int n = 0; n <= 9; n++)
				{
					int d = j * 10000000 + k * 1000000 + m * 100000 + n * 10000 + n * 1000 + m * 100 + k * 10 + j;
					if(s <= d && d <= e && is_prime(d))
						printf("%d\n", d);
				}
			}
		}
	}
}

void gen_nine(int s, int e)
{
	for(int j = 1; j <= 9; j += 2)
	{
		for(int k = 0; k <= 9; k++)
		{
			for(int m = 0; m <= 9; m++)
			{
				for(int n = 0; n <= 9; n++)
				{
					for(int p = 0; p <= 9; p++)
					{
						int d = j * 100000000 + k * 10000000 + m * 1000000 + n * 100000 + p * 10000 + n * 1000 + m * 100 + k * 10 + j;
						if(s <= d && d <= e && is_prime(d))
							printf("%d\n", d);
					}
				}
			}
		}
	}
}
func array[10] = {NULL, gen_one, gen_two, gen_three, gen_four, gen_five, gen_six, gen_seven, gen_eight, gen_nine};
int main()
{
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);
	int s, e, ns, ne;
	scanf("%d%d", &s, &e);
	ns = get_bits(s);
	ne = get_bits(e);
	for(int j = ns; j <= ne; j++)
		(*array[j])(s, e);
    return 0;
}

