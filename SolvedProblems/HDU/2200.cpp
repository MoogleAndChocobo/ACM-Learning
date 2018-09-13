#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <bitset>
#include <cmath>
#include <cctype>

using namespace std;

typedef long long ll;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

#define fli				freopen("in.txt", "r", stdin);
#define flo				freopen("out.txt", "w", stdout);
#define sync			ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define rep(i,a, b)		for(int i = a; i <= b; i++)
#define dow(i, a, b)	for(int i = a; i >= b; i--)
#define sfi(a)			scanf("%d", &a)
#define sfl(a)			scanf("%lld", &a)
#define sfd(a)			scanf("%lf", &a)
#define sfs(a)			scanf("%s", a)
#define mem(a)			memset(a, 0, sizeof(a))
#define mst(a)			memset(a, b, sizeof(a))
#define pb(a)			push_back(a)
#define all(c)			(c).begin(),(c).end()

const int MAX = 1e5 + 10;
const int N = 1e3 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1007;
const double EPS = (double)1e-7;
const LL LINF = 0x3f3f3f3f3f3f3f;
const int LMON[15] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
const int CMON[15] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
const int diro[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
const int dirt[6][3] = {{0,0,1},{0,0,-1},{1,0,0},{-1,0,0},{0,1,0},{0,-1,0}};

double gt(double a, double b)
{
	double ans = 1;
	for(double i = a; i >= a - b + 1; i--)
		ans *= i;
	for(double i = 2; i <= b; i++)
		ans /= i;
	return ans * (b - 1);
}

double init(double n)
{
	double ans = 0;
	for(double tmp = 0; tmp <= n - 2; tmp++)
		ans += gt(n, n - tmp);
	return ans;
}

int main()
{
#ifdef LOCAL
	//~ fli
	//~ flo
#endif	//LOCAL

	double n;
	while(~sfd(n))
	{
		printf("%.lf\n", init(n));
	}
	return 0;
}