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

int main()
{
	
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	char a[MAX], b[MAX];
	while(~scanf("%s%s", a, b))
	{
		int la = strlen(a), lb = strlen(b);
		int ans = la + lb;
		int cnt = 0;
		while(cnt < la)
		{
			rep(i, 0, lb - 1)
			{
				int now = b[i] - '0';
				if(cnt + i < la)
					now += a[i + cnt] - '0';
				if(now > 3)
					break;
				//~ printf("cnt = %d a[%d] = %d b[%d] = %d now = %d\n", cnt, i, a[i], i, b[i], now);
				if(i == lb - 1)
				{
					int tmp;
					if(la - cnt < lb)
						tmp = la + lb - (la - cnt);
					else
						tmp = la;
					ans = min(ans, tmp);
				}
			}
			cnt++;
		}
		cnt = 0;
		while(cnt < lb)
		{
			rep(i, 0, la - 1)
			{
				int now = a[i] - '0';
				if(cnt + i < lb)
					now += b[i + cnt] - '0';
				if(now > 3)
					break;
				//~ printf("cnt = %d a[%d] = %d b[%d] = %d now = %d\n", cnt, i, a[i], i, b[i], now);
				if(i == la - 1)
				{
					int tmp;
					if(lb - cnt < la)
						tmp = lb + la - (lb - cnt);
					else
						tmp = lb;
					ans = min(ans, tmp);
				}
			}
			cnt++;
		}
		printf("%d\n", ans);
	}
	return 0;
}