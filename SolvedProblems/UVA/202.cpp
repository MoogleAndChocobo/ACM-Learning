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

int main()
{
	  
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	int a, b;
	while(~scanf("%d%d", &a, &b))
	{
		int pre = a / b;
		int m = a, n = b;
		a %= b;
		bool vis[MAX] = {0};
		int ans[MAX] = {0};
		int store[MAX] = {0};
		vis[b] = true;
		int st = 0, en = 0;
		rep(i, 1, N)
		{
			if(vis[a])
			{
				en = i - 1;
				rep(j, 1, i)
				{
					if(store[j] == a)
					{
						st = j;
						break;
					}
				}
				break;
			}
			store[i] = a;
			vis[store[i]] = true;
			a *= 10;
			ans[i] = a / b;
			a %= b;
		}

		printf("%d/%d = %d.", m, n, pre);
		rep(i, 1, st - 1)
		{
			printf("%d", ans[i]);
		}
		int cnt = 0;
		putchar('(');
		rep(i, st, en)
		{
			cnt++;
			if(cnt > 50)
			{
				printf("...");
				break;
			}
			printf("%d", ans[i]);
		}
		putchar(')');
		putchar('\n');
		printf("   %d = number of digits in repeating cycle\n\n", en - st + 1);
	}
	return 0;
}