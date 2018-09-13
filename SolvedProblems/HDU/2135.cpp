#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cctype>
#include <queue>
#include <set>
#include <map>
#include <iostream>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LF;

#define fli				freopen("in.txt", "r", stdin);
#define flo				freopen("out.txt", "w", stdout);
#define sync 			ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define	rep(i, a, b)	for(int i = a; i <= b; i++)
#define dow(i, a, b)	for(int i = a; i >= b; i--)
#define mem(a)			memset(a, 0, sizeof(a))
#define mst(a, b)		memset(a, b, sizeof(a))
#define sfi(a)			scanf("%d", &a)
#define sfs(a)			scanf("%s", a)
#define sfl(a)			scanf("%lld", &a)
#define sfd(a)			scanf("%lf", &a)
#define pb(a)			push_back(a)
#define all(c)			(c).begin(),(c).end()
#define YES				puts("YES")
#define NO				puts("NO")
#define yes				puts("yes")
#define no				puts("no")
#define Yes				puts("Yes")
#define No				pus("No")

const int MAX = 1e3 + 10;
const int N = 205;
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1007;
const double EPS = (double)1e-10;
const int LMON[15] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
const int CMON[15] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
const int diro[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
const int dirt[6][3] = {{0,0,1},{0,0,-1},{1,0,0},{-1,0,0},{0,1,0},{0,-1,0}};

char s[MAX][MAX];
int n;

void print3(void)
{
	dow(i, n - 1, 0)
	{
		rep(j, 0, n - 1)
			putchar(s[j][i]);
		putchar('\n');
	}
}

void print0(void)
{
	rep(i, 0, n - 1)
	{
		rep(j, 0, n - 1)
			putchar(s[i][j]);
		putchar('\n');
	}
}

void print2(void)
{
	dow(i, n - 1, 0)
	{
		dow(j, n - 1, 0)
			putchar(s[i][j]);
		putchar('\n');
	}
}

void print1(void)
{
	rep(i, 0, n - 1)
	{
		dow(j, n - 1, 0)
			putchar(s[j][i]);
		putchar('\n');
	}
}

int main()
{
#ifdef LOCAL
	//~ fli
	//~ flo
#endif	//LOCAL

	LL opr;
	while(~scanf("%d%lld", &n, &opr))
	{
		rep(i, 0, n - 1)
			scanf("%s", s[i]);
		
		opr %= 4;
		if(opr < 0)
			opr += 4;

		if(opr == 3)
			print3();
		else if(opr == 2)
			print2();
		else if(opr == 1)
			print1();
		else
			print0();
	}
	return 0;
}