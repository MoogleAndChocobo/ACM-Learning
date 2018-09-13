//~ #define LOCAL

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<iostream>
#include<vector>
#include<sstream>
#include<map>
#include<set>
#include<cmath>
#include<cctype>
#include<functional>
#include<ctime>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LF;
typedef unsigned U;

const int dirnd[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
const int dirrd[6][3] = {{0,0,1},{0,0,-1},{1,0,0},{-1,0,0},{0,1,0},{0,-1,0}};
const int MAX = 1e4 + 10;
const int N = 1e3;
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f;

#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfu(a) scanf("%llu", &a)
#define sfd(a) scanf("%ld", &a)
#define sfs(a) scanf("%s", a)
#define sfc(a) getchar(a)
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))


int main()
{
	  
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	int cnt = 0;
	char pic[10][10];
	bool check = false;
	while(gets(pic[0]) != NULL)
	{
		if(!strcmp(pic[0], "Z"))
			break;
		if(check)
			putchar('\n');
		check = true;
		int nowx = 0, nowy = 0;
		rep(j, 0, 4)
			if(!isalpha(pic[0][j]))
			{
				nowx = 0, nowy = j;
				pic[nowx][nowy] = ' ';
			}
		rep(i, 1, 4)
		{
			gets(pic[i]);
			rep(j, 0, 4)
			{
				if(!isalpha(pic[i][j]))
				{
					nowx = i, nowy = j;
					pic[nowx][nowy] = ' ';
				}
			}
		}
		bool flag = true;
		char c;
		while(c = getchar())
		{
			if(c == '0')
				break;
			if(!flag)
				continue;
			if(c == 'A')
			{
				if(nowx > 0)
				{
					swap(pic[nowx][nowy], pic[nowx - 1][nowy]);
					nowx--;
				}
				else
					flag = false;
			}
			else if(c == 'B')
			{
				if(nowx < 4)
				{
					swap(pic[nowx][nowy], pic[nowx + 1][nowy]);
					nowx++;
				}
				else
					flag = false;
			}
			else if(c == 'L')
			{
				if(nowy > 0)
				{
					swap(pic[nowx][nowy - 1], pic[nowx][nowy]);
					nowy--;
				}
				else
					flag = false;
			}
			else if(c == 'R')
			{
				if(nowy < 4)
				{
					swap(pic[nowx][nowy], pic[nowx][nowy + 1]);
					nowy++;
				}
				else
					flag = false;
			}
		}
		getchar();
		printf("Puzzle #%d:\n", ++cnt);
		if(!flag)
		{
			printf("This puzzle has no final configuration.\n");
			mem(pic);
			continue;
		}
		rep(i, 0, 4)
		{
			rep(j, 0, 4)
			{
				putchar(pic[i][j]);
				if(j != 4)
					putchar(' ');
			}
			putchar('\n');
		}
		mem(pic);
	}
	return 0;
}