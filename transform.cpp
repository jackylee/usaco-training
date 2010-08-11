/*
LANG:  C++
ID: jacky.l1
PROB:transform
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

const int size = 13;
char grp[size][size];
char to[size][size];
char tgt[size][size];
char tmp[size][size];
char mid[size][size];

void inline copy(int n, char fr[][size], char to[][size])
{
	for(int j = 0; j < n; j++)
	{
		for(int k = 0; k < n; k++)
			to[j][k] = fr[j][k];
	}
}

bool equal(int n, char fr[][size], char to[][size])
{
	for(int j = 0; j < n; j++)
	{
		for(int k = 0; k < n; k++)
			if(fr[j][k] != to[j][k])
				return false;
	}
	return true;
}

void rotate(int n, char fr[][size], char to[][size])
{
	int j, k;
	for(j = 0; j < n; j++)
	{
		for(k = 0; k < n; k++)
		{
			to[k][n - 1 - j] = fr[j][k];
		}
	}
}

void rotate_90(int n, char fr[][size], char to[][size])
{
	rotate(n, fr, to);
	copy(n, to, tmp);
}

void rotate_180(int n, char fr[][size], char to[][size])
{
	rotate(n, fr, to);
	copy(n, to, tmp);
	rotate(n, tmp, to);
}

void rotate_270(int n, char fr[][size], char to[][size])
{
	rotate_180(n, fr, to);
	copy(n, to, tmp);
	rotate(n, tmp, to);
}


void reflect(int n, char fr[][size], char to[][size])
{
	for(int j = 0; j < n; j++)
	{
		for(int k = 0; k < n; k++)
		{
			to[j][k] = fr[j][k];
		}
	}
	for(int j = 0; j < n; j++)
	{
		for(int k = 0; k < n - 1 - k; k++)
		{
			swap(to[j][k], to[j][n - 1 - k]);
		}
	}
}

void compose(int n, char fr[][size], char to[][size])
{
	reflect(n, fr, to);
	copy(n, to, tmp);

	for(int j = 1; j <= 3; j++)
	{
		for(int k = 0; k < j; k++)
		{
			rotate(n, tmp, mid);
			copy(n, mid, tmp);
		}
		if(equal(n, mid, tgt))
		{
			copy(n, mid, to);
			break;
		}
	}
}

typedef void (*action)(int n, char fr[][size], char to[][size]);

action actions[6] = {rotate_90, rotate_180, rotate_270, reflect, compose, copy};

void print(int n, char grp[][size])
{
	for(int j = 0; j < n; j++)
	{
		for(int k = 0; k < n; k++)
		{
			fprintf(stderr, "%c", grp[j][k]);
		}
		fprintf(stderr, "\n");
	}
}

int main()
{
	int j, n;
	bool flag = false;
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);
	scanf("%d", &n);
	for(j = 0; j < n; j++)
		scanf("%s", grp[j]);
	for(j = 0; j < n; j++)
		scanf("%s", tgt[j]);
	for(j = 0; j < 6; j++)
	{
		(*actions[j])(n, grp, to);
		/*
		fprintf(stderr, "************************************\n");
		print(n, tgt);
		print(n, to);
		fprintf(stderr, "************************************\n");
		*/
		if(equal(n, tgt, to))
		{
			printf("%d\n", j + 1);
			flag = true;
			break;
		}
	}
	if(!flag)
		printf("7\n");
    return 0;
}

