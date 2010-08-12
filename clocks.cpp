/*
LANG:  C++
ID: jacky.l1
PROB:clocks
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
const int size = 262149;
bool used[size];
typedef struct node{
	int mask;
	int last;
	int op;
}node_t;

node_t q[size];
int input[9];

int get_bits(int mask, int n)
{
	return (mask >> (2 * n)) & 3;
}

void set_bits(int n, int val, int& mask)
{
	mask &= ~(3<<(2*n));
	mask |= (val<<(2*n));
}

char act[10][6] = {"", "ABDE", "ABC", "BCEF", "ADG", "BDEFH", "CFI", "DEGH","GHI","EFHI"};

int do_act(int mask, int j)
{
	int ret = mask;
	char *ch = act[j];
	while(*ch)
	{
		int last = get_bits(ret, *ch - 'A');
		last = (last + 1) % 4;
		set_bits(*ch - 'A', last, ret);
		ch++;
	}
	return ret;
}

void traceback(int cur, int st)
{
	if(q[cur].last == -1)
		return;
	traceback(q[cur].last, st);
	if(cur == st)
		printf("%d\n", q[cur].op);
	else
		printf("%d ", q[cur].op);
}

void bfs(int start)
{
	int he = 0, ta = 1;
	q[he].mask = start;
	q[he].last = -1;
	q[he].op = -1;
	used[q[he].mask] = true;
	while(he < ta)
	{
		node_t *cur = &q[he++];
		if(cur->mask == 0)
		{
			traceback(he - 1, he - 1);
			break;
		}
		for(int j = 1; j <= 9; j++)
		{
			int nxt = do_act(cur->mask, j);
			if(!used[nxt])
			{
				used[nxt] = true;
				q[ta].mask = nxt;
				q[ta].last = he - 1;
				q[ta++].op = j;
			}
		}
	}	
}

int main()
{
    freopen("clocks.in", "r", stdin);
    freopen("clocks.out", "w", stdout);
	for(int j = 0; j < 9; j++)
	{
		scanf("%d", &input[j]);
	}
	int st = 0;
	for(int j = 0; j < 9; j++)
	{
		st |= (((input[j] / 3) % 4) << (2 * j));
	}
	bfs(st);
    return 0;
}
