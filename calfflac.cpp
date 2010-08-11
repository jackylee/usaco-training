/*
LANG:  C++
ID: jacky.l1
PROB:calfflac
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
const int size = 20007;
const int line_sz = 2007;
char str[size];
char cpt[size];
char line[line_sz];
int idx[size];
int fr, to;

bool is_alpha(char ch)
{
	return ('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z');
}

int main()
{
    freopen("calfflac.in", "r", stdin);
    freopen("calfflac.out", "w", stdout);
	while(cin.getline(line, line_sz))
	{
		line[strlen(line)] = '\n';
		strcat(str, line);
		memset(line, 0, sizeof(line));
	}
	str[strlen(str)] = 0;
	int j, k, len =  strlen(str);
	for(j = 0, k = 0; j < len; j++)
	{
		if(is_alpha(str[j]))
		{
			idx[k] = j;
			cpt[k++] = tolower(str[j]);
		}
	}
	cpt[k] = 0;
	//printf("formated: %s\n", cpt);
	int ans = 1,  cur, f,  r, t;
	len = strlen(cpt);
	for(j = 0; j < len; j++)
	{
		for(k = 0; k < len; k++)
		{
			if(j - k < 0)break;
			if(j + k >= len)break;
			if(cpt[j - k] != cpt[j + k])break;
			else if(2 * k + 1 > ans)
			{
				ans = 2 * k + 1;
				f = j - k, t = j + k;
			}
		}
	}
    for(j = 0; j + 1 < len; j++)
	{
		k = j + 1;
		for(r = 0; ; r++)
		{
			if(j - r < 0)break;
			if(k + r >= len)break;
			if(cpt[j - r] != cpt[k + r])break;
			else if(2 * r + 2 > ans)
			{
				ans = 2 * r + 2;
				f = j - r, t = k + r;
			}
		}
	}
	printf("%d\n", ans);
	for(j = idx[f]; j <= idx[t]; j++)
	{
		printf("%c", str[j]);
	}
	printf("\n");
    return 0;
}

