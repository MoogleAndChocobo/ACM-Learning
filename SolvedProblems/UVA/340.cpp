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
const int N = 1e3;
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f;

#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfu(a) scanf("%llu", &a)
#define sfd(a) scanf("%ld", &a)
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


	int cnt = 0;
	int n;
	while(~sfi(n) && n)
	{
		printf("Game %d:\n", ++cnt);
		int ans[MAX] = {0};
		int rec[15] = {0};
		rep(i, 1, n)
		{
			sfi(ans[i]);
			rec[ans[i]]++;
		}
		while(true)
		{
			int now[15] = {0};
			int a = 0, b = 0;
			int guess[MAX] = {0};
			rep(i, 1, n)
			{
				sfi(guess[i]);
				if(guess[i] == ans[i])
					a++;
				now[guess[i]]++;
			}
			bool flag = true;
			rep(i, 1, n)
			{
				if(guess[i])
				{
					flag = false;
					break;
				}
			}
			if(flag)
				break;
			rep(i, 1, 9)
			{
				b += min(now[i], rec[i]);
			}
			printf("    (%d,%d)\n", a, b - a);
		}
	}
	return 0;
}