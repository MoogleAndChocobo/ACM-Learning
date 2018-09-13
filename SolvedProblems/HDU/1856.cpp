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
const int MAX = 1e6 + 10;
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

struct Store
{
	int x, y;
	Store(int xx = 0, int yy = 0):x(xx), y(yy){}
} store[MAXN];

set<int> uniq;

struct Ufs
{
	int prt[MAX];

	void init(void)
	{
		for(set<int>::iterator it = uniq.begin(); it != uniq.end(); it++)
		{
			prt[*it] = *it;
		}
	}

	int findprt(int x)
	{
		while(x != prt[x])
			x = prt[x];
		return x;
	}

	void unite(int x, int y)
	{
		int px = findprt(x);
		int py = findprt(y);
		prt[x] = prt[y] = prt[px] = prt[py] = min(px, py);
		return;
	}

	int getcnt(void)
	{
		map<int,int> cnt;
		set<int> ans;
		for(set<int>::iterator it = uniq.begin(); it != uniq.end(); it++)
		{
			int tmp = findprt(*it);
			ans.insert(tmp);
			cnt[tmp]++;
		}
		int res = 0;
		for(set<int>::iterator it = ans.begin(); it != ans.end(); it++)
			res = max(res, cnt[*it]);
		return res;
	}
} u;

void init(void)
{
	uniq.clear();
	mem(store);
}

int main()
{
	
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	int n;
	while(~sfi(n))
	{
		if(!n)
		{
			printf("1\n");
			continue;
		}
		init();
		rep(i, 1, n)
		{
			scanf("%d%d", &store[i].x, &store[i].y);
			uniq.insert(store[i].x);
			uniq.insert(store[i].y);
		}
		u.init();
		rep(i, 1, n)
		{
			u.unite(store[i].x, store[i].y);
		}
		printf("%d\n", u.getcnt());
	}
	return 0;
}