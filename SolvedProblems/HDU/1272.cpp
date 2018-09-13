
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
const int MAX = 1e5 + 10;
const int N = 1e5;
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
	set<int> s;

	void init(int n)
	{
		s.clear();
		rep(i, 1, n)
		{
			prt[i] = i;
		}
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

	void pushtwo(int x, int y)
	{
		s.insert(x);
		s.insert(y);
	}

	bool getcnt(void)
	{
		set<int> ans;
		for(set<int>::iterator it = s.begin(); it != s.end(); it++)
		{
			ans.insert(findprt(*it));
		}
		return ans.size() <= 1;
	}
};

int main()
{
	
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	int x, y;
	while(~scanf("%d%d", &x, &y))
	{
		if(x == -1 && y == -1)
			break;

		if(!x && !y)
		{
			puts("Yes");
			continue;
		}
		Ufs u;
		bool flag = true;
		u.init(N);
		flag = u.unite(x, y);
		u.pushtwo(x, y);
		while(~scanf("%d%d", &x, &y))
		{
			if(!x && !y)
			{
				if(flag)
					flag = u.getcnt();
				puts(flag ? "Yes" : "No");
				break;
			}
			else
			{
				if(flag)
				{
					flag = u.unite(x, y);
					u.pushtwo(x, y);
				}
			}
		}
	}
	return 0;
}