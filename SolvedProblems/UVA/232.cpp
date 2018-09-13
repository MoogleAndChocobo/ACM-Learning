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

struct Node
{
	int order;
	string word;
	Node(int oo = 0, string ww = ""):order(oo), word(ww){}
	friend bool operator <(Node a, Node b)
	{
		return a.order < b.order;
	}
};

int main()
{
	  
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	bool flag = false;
	int kase = 0;
	int m, n;
	while(~sfi(m) && m)
	{
		sfi(n);
		if(flag)
			putchar('\n');
		flag = true;
		printf("puzzle #%d:\n", ++kase);
		char pic[15][15] = {0};
		rep(i, 1, m)
		{
			getchar();
			rep(j, 1, n)
			{
				pic[i][j] = getchar();
			}
		}
		int order[15][15] = {0};
		int cnt = 0;
		rep(i, 1, m)
		{
			rep(j, 1, n)
			{
				if((i == 1 || j == 1 || pic[i - 1][j] == '*' || pic[i][j - 1] == '*') && pic[i][j] != '*')
					order[i][j] = ++cnt;
			}
		}

		set<Node> across;
		rep(i, 1, m)
		{
			rep(j, 1, n)
			{
				if(pic[i][j] != '*')
				{
					Node now;
					now.order = order[i][j];
					for(int k = j; k <= n && pic[i][k] != '*'; k++, j++)
					{
						now.word += pic[i][k];
					}
					across.insert(now);
				}
			}
		}
		printf("Across\n");
		for(set<Node>::iterator it = across.begin(); it != across.end(); it++)
		{
			printf("%3d.", it->order);
			cout << it->word << endl;
		}

		set<Node> down;
		rep(i, 1, n)
		{
			rep(j, 1, m)
			{
				if(pic[j][i] != '*')
				{
					Node now;
					now.order = order[j][i];
					for(int k = j; k <= m && pic[k][i] != '*'; k++, j++)
					{
						now.word += pic[k][i];
					}
					down.insert(now);
				}
			}
		}
		printf("Down\n");
		for(set<Node>::iterator it = down.begin(); it != down.end(); it++)
		{
			printf("%3d.", it->order);
			cout << it->word << endl;
		}
	}
	return 0;
}