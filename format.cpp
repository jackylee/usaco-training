#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int line_size = 99;
char str[10000];

int main()
{
	freopen("calfflac.out", "r", stdin);
	char line[line_size];
	int j = 0, k = 0;
	while(cin.getline(line, line_size))
	{
		for(k = 0; k < strlen(line); k++)
		{
			if(isalpha(line[k]))
				str[j++] = tolower(line[k]);
		}
	}
	str[j] = 0;
	if(strlen(str) % 2 == 0)
	{
		printf("%d %d %c %c\n", strlen(str)/2, strlen(str)/2 - 1, str[strlen(str)/2], str[strlen(str)/2 - 1]);
		int j = strlen(str)/2 - 1, k = j + 1;
		while(true)
		{
			j--, k++;
			if(j >= 0 && k < strlen(str))
				printf("(%c %c)", str[j], str[k]);
			else
				break;
		}
	    printf("\n");	
	}
	else
	{
		printf("%d %c\n", strlen(str)/2, str[strlen(str)/2]);
	}

	return 0;
}
