/*
LANG:  C++
ID: jacky.l1
PROB:milk3
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
const int size = 23;
bool can[size];
int cnt, cap_A, cap_B, cap_C;
bool visited[size][size][size];

void dfs(int A, int B, int C)
{
	if(A < 0 || B < 0 || C < 0)
		return;
	if(A > cap_A || B > cap_B || C > cap_C)
		return;
	if(visited[A][B][C])
		return;
	visited[A][B][C] = true;
	int nA, nB, nC;
	if(A == 0){
		//fprintf(stderr, "%d %d %d\n", A, B, C);
		if(!can[C])
		{
			can[C] = true;
			cnt++;
		}
	}
	if(A + B <= cap_A)
	{
		nA = A, nB = B, nC = C;
		nA += B;
		nB = 0;
		dfs(nA, nB, C);
	}
	else
	{
		nA = A, nB = B, nC = C;
		nB -=  (cap_A - A);
		nA = cap_A;
		dfs(nA, nB, C);
	}
	if(A + C <= cap_A)
	{
		nA = A, nB = B, nC = C;
		nA += C;
		nC = 0;
		dfs(nA, B, nC);
	}
	else
	{
		nA = A, nB = B, nC = C;
		nC -= (cap_A - A);
		nA = cap_A;
		dfs(nA, B, nC);
	}
	if(B + A <= cap_B)
	{
		nA = A, nB = B, nC = C;
		nB += A;
		nA = 0;
		dfs(nA, nB, C);
	}
	else
	{
		nA = A, nB = B, nC = C;
		nA -= (cap_B - B);
		nB = cap_B;
		dfs(nA, nB, C);
	}
	if(B + C <= cap_B)
	{		
		nA = A, nB = B, nC = C;
		nB += C;
		nC = 0;
		dfs(A, nB, nC);
	}
	else
	{
		nA = A, nB = B, nC = C;
		nC -= (cap_B - B);
		nB = cap_B;
		dfs(A, nB, nC);
	}
	if(A + C <= cap_C)
	{
		nA = A, nB = B, nC = C;
		nC += A;
		nA = 0;
		dfs(nA, B, nC);
	}
	else
	{
		nA = A, nB = B, nC = C;
		nA -= (cap_C - C);
		nC = cap_C;
		dfs(nA, B, nC);
	}
}

int main()
{
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);
	scanf("%d%d%d", &cap_A, &cap_B, &cap_C);
	int A, B, C;
	A = 0, B = 0, C = cap_C;
	memset(can, false, sizeof(can));
	memset(visited, false, sizeof(visited));
	dfs(A, B, C);
	for(int j = 0, k = 0; j <= 20; j++)
	{
		if(can[j])
		{
			printf("%d", j);
			k++;
			if(k != cnt)
				printf(" ");
			else
				printf("\n");
		}
	}
    return 0;
}

