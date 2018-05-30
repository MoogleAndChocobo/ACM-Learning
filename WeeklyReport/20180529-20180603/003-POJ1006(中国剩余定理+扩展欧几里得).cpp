#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cctype>
#include <bitset>
#include <functional>
#include <list>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define pb(a) push_back(a)
#define all(a) a.begin(), a.end()
#define sync ios::sync_with_stdio(0); cin.tie(0);

const int MAX = 1e5 + 50;
const int N = 1e5;
const int MOD = 1e9 + 7;
const double EPS = 1e-6;

int m[5] = {23, 28, 33};
int a[5];

int ex_gcd(int a, int b, int &x, int &y)
{
	if (!b)
	{
		x = 1;
		y = 0;
		return a;
	}
	else
	{
		int r = ex_gcd(b, a % b, y, x);
		y -= x * (a / b);
		return r;
	}
}

int crt()
{
	int n = 3;
	int M = 1;
	rep(i, 0, n - 1)
		M *= m[i];
	int ret = 0;
	rep(i, 0, n - 1)
	{
		int x, y;
		int tm = M / m[i];
		ex_gcd(tm, m[i], x, y);
		ret = (ret + tm * x * a[i]) % M;
	}
	return (ret + M) % M;
}

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
	//~ freopen("out.txt", "w", stdout);
#endif

	int kase = 0;
	int st;
	while(~scanf("%d%d%d%d", &a[0], &a[1], &a[2], &st))
	{
		if(a[0] == -1 && a[1] == -1 && a[2] == -1 && st == -1)
			break;
		rep(i, 0, 2)
			a[i] %= m[i];
		int ans = crt() - st;
		while(ans <= 0)
			ans += 21252;
		printf("Case %d: the next triple peak occurs in %d days.\n", ++kase, ans);
	}
	return 0;
}
