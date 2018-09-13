//~ #define LOCAL

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>

using namespace std;

typedef long long LL;

const int MAXP = 2e6 + 10;
const int MAXN = 6e2 + 10;

#define mem(a) memset(a, 0, sizeof(a))
#define rep(i, a, b) for(int i = a; i <= b; i++)

struct Ufs
{
	int prt[MAXN];
	void init(int n)
	{
		rep(i, 1, n)
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
		prt[x] = prt[y] = prt[px] = prt[py] = min(px, py);
		return px != py;
	}
	bool check(int n)
	{
		set<int> ans;
		rep(i, 1, n)
		{
			ans.insert(findprt(i));
			if(ans.size() > 1)
				return false;
		}
		return true;
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
	Ufs u;
	vector<Edge> e;
	void init(void)
	{
		e.clear();
		return;
	}
	void addedge(int u, int v, int w)
	{
		e.push_back(Edge(u, v, w));
		return;
	}
	int solve(int n)
	{
		u.init(n);
		int cnt = 0, ans = 0, len = e.size();
		sort(e.begin(), e.end());
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
		if(u.check(n))
			return ans;
		return -1;
	}
} k;

bool isNotPrime[MAXP] = {true, true};
int prime[MAXP];
bool check[MAXP];
int rec[MAXN];
bool vis[MAXN];
int cnt;


void init(void)
{
	k.init();
	mem(rec);
	mem(vis);
	return;
}

void pre(void)
{
	rep(i, 2, MAXP - 5)
	{
		if(!isNotPrime[i])
			prime[cnt++] = i;
		for(int j = 0; j < cnt && i * prime[j] < MAXP - 5; j++)
		{
			isNotPrime[i * prime[j]] = true;
			if(!(i % prime[j]))
				break;
		}
	}
	rep(i, 0, cnt - 1)
		check[prime[i]] = true;
	return;
}

int main()
{

#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	pre();
	int test;
	scanf("%d", &test);
	while(test--)
	{
		int n;
		scanf("%d", &n);
		init();
		rep(i, 1, n)
			scanf("%d", &rec[i]);
		rep(i, 1, n - 1)
		{
			rep(j, i + 1, n)
			{
				if(check[rec[i]] || check[rec[j]] || check[rec[i] + rec[j]])
				{
					int w = min(min(rec[i], rec[j]), abs(rec[i] - rec[j]));
					k.addedge(i, j, w);
					vis[i] = vis[j] = true;
				}
			}
		}
		bool flag = true;
		rep(i, 1, n)
		{
			if(!vis[i])
			{
				flag = false;
				break;
			}
		}
		if(flag)
			printf("%d\n", k.solve(n));
		else
			printf("-1\n");
	}
	return 0;
}