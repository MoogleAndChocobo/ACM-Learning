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
const int MAX = 1e3 + 10;
const int MAXN = 1e5 + 10;
const int N = 1e6;
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 0.000001;

#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfu(a) scanf("%llu", &a)
#define sfd(a) scanf("%lf", &a)
#define sfs(a) scanf("%s", a)
#define sfc(a) getchar(a)
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define pb(a) push_back(a)

struct Ufs
{
	int prt[MAX];

	void init(int n)
	{
		rep(i, 1, n)
			prt[i] = i;
	}

	int findprt(int x)
	{
		while(x != prt[x])
			x = prt[x];
		return x;
	}

	bool unite(int x, int y)
	{
		int px = findprt(x);
		int py = findprt(y);
		prt[x] = prt[y] = prt[px] = prt[py] = min(px, py);
		return px != py;
	}

	bool getcnt(int n)
	{
		set<int> ans;
		rep(i, 1, n)
			ans.insert(findprt(i));
		return ans.size() == 1;
	}
};

struct Kruskal
{
	struct Edge
	{
		int u, v, w;
		Edge(int uu = 0, int vv = 0, int ww = 0):u(uu), v(vv), w(ww){}
		friend bool operator <(Edge a, Edge b)
		{
			return a.w < b.w;
		}
	};

	vector<Edge> e;
	Ufs u;

	void init(int n)
	{
		u.init(n);
		e.clear();
	}

	void addedge(int u, int v, int w)
	{
		e.pb(Edge(u, v, w));
	}

	int solve(int n)
	{
		sort(e.begin(), e.end());
		int ans = 0, cnt = 0;
		int len = e.size();
		rep(i, 0, len - 1)
		{
			if(u.unite(e[i].u, e[i].v))
			{
				ans += e[i].w;
				cnt++;
			}
			if(cnt == n - 1)
				break;
		}
		if(u.getcnt(n) == 1)
			return ans;
		return -1;
	}
} k;

int main()
{
	
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	int road, n;
	while(~scanf("%d%d", &road, &n))
	{
		if(!road)
			break;
		k.init(n);
		while(road--)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			k.addedge(u, v, w);
		}
		int ans = k.solve(n);
		if(ans == -1)
			puts("?");
		else
			printf("%d\n", ans);
	}
	return 0;
}