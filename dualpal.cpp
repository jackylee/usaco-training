/*
LANG:  C++
ID: jacky.l1
PROB:dualpal
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
char str[size];

bool palindrome(const char *str)
{
	int j, len = strlen(str);
	for(j = 0; j < len - 1 - j; j++)
	{
		if(str[j] != str[len - 1 - j])
			return false;		
	}
	return true;
}

void reverse(char *str)
{
	int j, len = strlen(str);
	for(j = 0; j < len - 1 - j; j++)
		swap(str[j], str[len - 1 - j]);
}

void int2base(int n, int base, char *str)
{
	int j = 0;
	while(n){
		str[j++] = "0123456789"[n % base];
		n /= base;
	}
	str[j] = '\0';
}

bool judge(int n)
{
	int j, cnt = 0;
	for(j = 2; j <= 10; j++)
	{
		int2base(n, j, str);
		if(palindrome(str))
			cnt++;
		if(cnt == 2)
			return true;
	}
	return false;
}

int main()
{
	int N, n, j, cnt;
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);
	scanf("%d%d", &N, &n);
	j = n + 1;
	while(cnt != N)
	{
		if(judge(j))
		{
			printf("%d\n", j);
			cnt++;
		}
		j++;
	}
    return 0;
}
