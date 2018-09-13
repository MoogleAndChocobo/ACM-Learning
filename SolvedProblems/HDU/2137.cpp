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

char s[MAX];
int n;

void p0(void)
{
	//~ int num = n / 2;
	//~ rep(i, 1, num)
		//~ putchar('\n');
	puts(s);
	//~ rep(i, 1, num)
		//~ putchar('\n');
}

void p1(void)
{
	dow(i, n, 1)
	{
		rep(j, 1, i - 1)
			putchar(' ');
		putchar(s[i - 1]);
		putchar('\n');
	}
}

void p2(void)
{
	int num = n / 2;
	dow(i, n, 1)
	{
		rep(j, 1, num)
			putchar(' ');
		putchar(s[i - 1]);
		putchar('\n');
	}
}

void p3(void)
{
	dow(i, n, 1)
	{
		rep(j, 1, n - i)
			putchar(' ');
		putchar(s[i - 1]);
		putchar('\n');
	}
}

void p4(void)
{
	//~ int num = n / 2;
	//~ rep(i, 1, num)
		//~ putchar('\n');
	dow(i, n, 1)
		putchar(s[i - 1]);
	putchar('\n');
	//~ rep(i, 1, num)
		//~ putchar('\n');
}

void p5(void)
{
	rep(i, 1, n)
	{
		rep(j, 1, n - i)
			putchar(' ');
		putchar(s[i - 1]);
		putchar('\n');
	}
}

void p6(void)
{
	int num = n / 2;
	rep(i, 1, n)
	{
		rep(j, 1, num)
			putchar(' ');
		putchar(s[i - 1]);
		putchar('\n');
	}
}

void p7(void)
{
	rep(i, 1, n)
	{
		rep(j, 1, i - 1)
			putchar(' ');
		putchar(s[i - 1]);
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
	while(~scanf("%s%lld", s, &opr))
	{
		n = strlen(s);
		opr %= 8;
		if(opr < 0)
			opr += 8;
		switch(opr)
		{
			case 0: p0(); break;
			case 1: p1(); break;
			case 2: p2(); break;
			case 3: p3(); break;
			case 4: p4(); break;
			case 5: p5(); break;
			case 6: p6(); break;
			case 7: p7(); break;
		}
	}
	return 0;
}