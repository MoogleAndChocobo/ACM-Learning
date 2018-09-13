//~ #define LOCAL

#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define rep(a, b) for(int i = a; i <= b; i++)
#define mst(a) memset(a, 0, sizeof(a))

const int MAX = 2 * 1e3 + 50;
const int MAX_LEN = 10;

char s[MAX][MAX_LEN];

int chkdif(int x, int y)
{
	int cnt = 0;
	rep(0, 6)
	{
		if(s[x][i] != s[y][i])
			cnt++;
	}
	return cnt;
}

struct Ufs
{
	int prt[MAX];

	void init(int n)
	{
		rep(1, n)
			prt[i] = i;
		return;
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
		prt[x] = prt[px] = prt[y] = prt[py] = min(px, py);
		return px != py;
	}
};

struct Kruskal
{
	
	struct Edge
	{
		int u, v, w;
		Edge(int uu, int vv, int ww):u(uu), v(vv), w(ww){}
		friend bool operator <(Edge a, Edge b)
		{
			return a.w < b.w;
		}
	};

	vector<Edge> e;
	Ufs u;

	void init(void)
	{
		e.clear();
	}

	void addedge(int u, int v, int w)
	{
		e.push_back(Edge(u, v, w));
	}

	int solve(int n)
	{
		u.init(n);
		int cnt = 0, ans = 0;
		int len = e.size();
		sort(e.begin(), e.end());
		rep(0, len - 1)
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
	freopen("in.txt", "r", stdin);
#endif
	
	int n;
	while(~scanf("%d", &n))
	{
		if(!n)
			break;
		k.init();
		mst(s);
		rep(1, n)
			scanf("%s", s[i]);
		rep(1, n - 1)
			for(int j = i + 1; j <= n; j++)
				k.addedge(i, j, chkdif(i, j));
		printf("The highest possible quality is 1/%d.\n", k.solve(n));
	}
	return 0;
}