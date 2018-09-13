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

	int T;
	sfi(T);
	while(T--)
	{
		char s[MAX] = {0};
		sfs(s);
		int len = strlen(s);
		int cnt = 0;
		int ans = 0;
		rep(i, 0, len - 1)
		{
			if(s[i] == 'O')
			{
				ans += ++cnt;
			}
			else
				cnt = 0;
		}
		printf("%d\n", ans);
	}
	return 0;
}