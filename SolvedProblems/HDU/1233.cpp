//~ #define LOCAL

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<set>
#include<map>
#include<iostream>
#include<cmath>
#include<cctype>
#include<sstream>
#include<iomanip>
#include<ctime>
#include<bitset>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned U;

const int MAX = 1e3 + 10;
const int N = 5e2 + 10;
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f;
const double EPS = 0.00000001;
const int MOD = 1e9 + 7;
const LL LMOD = 1e9 + 7;

#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define sfd(a) scanf("%lf", &a)
#define pb(a) push_back(a)
#define mem(a) memset(a, 0, sizeof(a))
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mst(a, b) memset(a, b, sizeof(a))

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
		e.clear();
		u.init(n);
	}
	void addedge(int u, int v, int w)
	{
		e.pb(Edge(u, v, w));
	}
	int solve(int n)
	{
		sort(e.begin(), e.end());
		int ans = 0, cnt = 0, len = e.size();
		rep(i, 0, len - 1)
		{
			if(u.unite(e[i].u, e[i].v))
			{
				cnt++;
				ans += e[i].w;
			}
			if(cnt == n - 1)
				break;
		}
		return ans;
	}
} k;

int main()
{
	
#ifdef LOCAL
	fropen("in.txt", "r", stdin);
#endif	//LOCAL

	//~ ios::sync_with_stdio(false);
	//~ cin.tie(0);

	int n;
	while(~sfi(n) && n)
	{
		k.init(n);
		int road = n * (n - 1) / 2;
		rep(i, 1, road)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			k.addedge(u, v, w);
		}
		printf("%d\n", k.solve(n));
	}
	return 0;
}