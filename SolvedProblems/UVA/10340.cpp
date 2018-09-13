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
const int MAX = 1e5 + 10;
const int N = 10;
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

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

char org[MAX], ans[MAX];

int main()
{
	  
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	
	while(~scanf("%s%s", org, ans))
	{
		int lena = strlen(org), lenb = strlen(ans);
		int cnt = 0;
		rep(i, 0, lenb - 1)
		{
			if(ans[i] == org[cnt])
			{
				if(cnt + 1 == lena)
				{
					cnt++;
					break;
				}
				else
					cnt++;
			}
		}
		if(cnt != lena)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}