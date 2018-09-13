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
const int MAX = 1e3 + 10;
const int N = 1e4;
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

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

	void unite(int x, int y)
	{
		int px = findprt(x);
		int py = findprt(y);
		prt[x] = prt[y] = prt[px] = prt[py] = min(px, py);
	}

	int getcnt(int n)
	{
		set<int> ans;
		rep(i, 1, n)
			ans.insert(findprt(i));
		return ans.size();
	}
} u;

int main()
{
	
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	int n, road;
	while(~sfi(n) && n)
	{
		scanf("%d", &road);
		u.init(n);
		rep(i, 1, road)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			u.unite(x, y);
		}
		printf("%d\n", u.getcnt(n) - 1);
	}
	return 0;
}