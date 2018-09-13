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

int main()
{
	  
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	char a[MAX], b[MAX];
	while(~scanf("%s%s", a, b))
	{
		int lena = strlen(a);
		int lenb = strlen(b);
		int cnta[MAX] = {0}, cntb[MAX] = {0};
		if(lena != lenb)
			return 0;
		rep(i, 0, lena - 1)
		{
			cnta[(int)a[i]]++;
			cntb[(int)b[i]]++;
		}
		sort(cnta, cnta + 257);
		sort(cntb, cntb + 257);
		bool flag = true;
		rep(i, 1, 256)
		{
			if(cnta[i] != cntb[i])
			{
				flag = false;
				break;
			}
		}
		printf("%s\n", flag ? "YES" : "NO");
	}
	return 0;
}