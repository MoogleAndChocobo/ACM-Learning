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
const int MAX = 1e3 + 3;
const int N = 65535;
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfu(a) scanf("%llu", &a)
#define sfd(a) scanf("%lf", &a)
#define sfs(a) scanf("%s", a)
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define pb(a) push_back(a)

LL store[5][MAX];

LL kase = 0;

int main()
{

#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	LL l, m, n;
	while(~scanf("%lld%lld%lld", &l, &m, &n))
	{
		rep(i, 1, l)
			sfl(store[1][i]);
		rep(i, 1, m)
			sfl(store[2][i]);
		rep(i, 1, n)
			sfl(store[3][i]);

		set<LL> proc;
		rep(i, 1, l)
		{
			rep(j, 1, m)
			{
				proc.insert(store[1][i] + store[2][j]);
			}
		}
		sort(store[3] + 1, store[3] + n + 1);

		printf("Case %lld:\n", ++kase);
		LL ques;
		sfl(ques);
		rep(i, 1, ques)
		{
			LL need;
			sfl(need);
			bool flag = false;
			rep(j, 1, n)
			{
				LL now = need - store[3][j];
				if(proc.find(now) != proc.end())
				{
					flag = true;
					break;
				}
			}
			if(flag)
				puts("YES");
			else
				puts("NO");
		}
	}
	return 0;
}