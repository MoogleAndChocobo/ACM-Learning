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

double gt(char c)
{
	if(c == 'C')
		return 12.01;
	if(c == 'H')
		return 1.008;
	if(c == 'O')
		return 16.00;
	if(c == 'N')
		return 14.01;
	return 0;
}

int main()
{
	  
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL


	int T;
	sfi(T);
	while(T--)
	{
		int n;
		sfi(n);
		int cnt[15] = {0};
		rep(i, 1, n)
		{
			char s[15] = {0};
			sprintf(s, "%d", i);
			int len = strlen(s);
			rep(i, 0, len - 1)
				cnt[s[i] - '0']++;
		}
		rep(i, 0, 9)
		{
			printf("%d", cnt[i]);
			if(i != 9)
				putchar(' ');
			else
				putchar('\n');
		}
	}
	return 0;
}