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
const int N = 10;
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

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
	int h, w;
	bool vis;
	Node(int hh = 0, int ww = 0, bool vv = false):h(hh), w(ww), vis(vv){}
	friend bool operator ==(Node a, Node b)
	{
		return a.h == b.h && a.w == b.w;
	}
};


int main()
{
	  
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	
	int h, w;
	while(~scanf("%d%d", &h, &w))
	{
		Node org[N];
		org[0] = Node(min(h, w), max(h, w));
		rep(i, 1, 5)
		{
			scanf("%d%d", &h, &w);
			org[i] = Node(min(h, w), max(h, w));
		}

		Node s[N];
		int cnt = 0;
		rep(i, 0, 5)
		{
			if(!org[i].vis)
			{
				rep(j, i + 1, 5)
				{
					if(org[i] == org[j])
					{
						s[cnt++] = org[i];
						org[i].vis = org[j].vis = true;
						break;
					}
				}
			}
		}
		if(cnt < 3)
		{
			printf("IMPOSSIBLE\n");
			continue;
		}

		int ha = s[0].h, wa = s[0].w;
		int hb = s[1].h, wb = s[1].w;
		int hc = s[2].h, wc = s[2].w;

		if((ha == hb && wa == hc && wb == wc)
		|| (ha == hb && wa == wc && hc == wb)
		|| (ha == wb && wa == hc && hb == wc)
		|| (ha == wb && wa == wc && hb == hc)
		|| (ha == hc && wa == hb && wb == wc)
		|| (ha == hc && wa == wb && hb == wc)
		|| (ha == wc && wa == hb && wb == hc)
		|| (ha == wc && wa == wb && hb == hc))
			printf("POSSIBLE\n");
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}