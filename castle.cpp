/*
LANG:  C++
ID: jacky.l1
PROB:castle
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

const int size = 53;

bool used[size * size];
int ids[size * size];
int cnt[size * size];
int adj[size * size][5];
int grp[size][size];
int mask[] = {1, 2, 4, 8};
int dx[] = {0, -1, 0, 1, };
int dy[] = {-1, 0, 1, 0, };
char dir[] = {'W', 'N', 'E', 'S'};

void init_grp(int r, int c)
{
	for(int j = 0; j < r; j++)
	{
		for(int k = 0; k < c; k++)
		{
			for(int m = 0; m < 4; m++)
			{
				if(!(grp[j][k] & mask[m]))
				{
					int nx = j + dx[m];
					int ny = k + dy[m];
					if(nx < 0 || ny < 0 || nx >= r || ny >= c)continue;					
					adj[j * c + k][++adj[j * c + k][0]] = nx * c + ny;
				}
			}
		}
	}
}

int get_max_room(int ans)
{
	int ret = 0;
	for(int j = 0; j < ans; j++)
		ret = max(ret, cnt[j]);
	return ret;
}

void mark(int x, int y, int id, int r, int c)
{
	ids[x * c + y] = id;
	used[x * c + y] = true;
	cnt[id]++;
	for(int j = 1; j <= adj[x * c + y][0]; j++)
	{
		if(!used[adj[x * c + y][j]])
			mark(adj[x * c + y][j] / c, adj[x * c + y][j] % c, id, r, c);		
	}
}

void flood_fill(int r, int c, int& cnt)
{
	int j, k;
	for(j = 0; j < r; j++)
	{
		for(k = 0; k < c; k++)
		{
			if(!used[j * c + k])
			{
				mark(j, k, cnt++, r, c);
			}
		}
	}
}

int find_max(int r, int c, int& x, int& y, char& op)
{
	int ans = 0;
	for(int k = 0; k < c; k++)
	{
		for(int j = r - 1; j >= 0; j--)
		{
			for(int m = 0; m < 4; m++)
			{
				if((grp[j][k] & mask[m]) == 2 || (grp[j][k] & mask[m]) == 4)
				{
					int nx = j + dx[m];
					int ny = k + dy[m];
					if(nx < 0 || ny < 0 || nx >= r || ny >= c)continue;					
					if(ids[j * c + k] != ids[nx * c + ny]){
						if(cnt[ids[j * c + k]] + cnt[ids[nx * c + ny]] > ans)
						{
							ans = cnt[ids[j * c + k]] + cnt[ids[nx * c + ny]];
							x = j + 1, y = k + 1;
							op = dir[m];
						}
					}
				}
			}
		}
	}
	return ans;
}

int main()
{
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);
	int r, c, ans, x, y;
	char op;
	scanf("%d%d", &c, &r);
	for(int j = 0; j < r; j++)
	{
		for(int k = 0; k < c; k++)
		{
			scanf("%d", &grp[j][k]);
		}
	}	
	ans = 0;
	init_grp(r, c);
	//print_adj(r, c);
	flood_fill(r, c, ans);
	printf("%d\n", ans);
	int max_room = get_max_room(ans);
	printf("%d\n", max_room);
	printf("%d\n", find_max(r, c, x, y, op));
	printf("%d %d %c\n", x, y, op);
    return 0;
}
