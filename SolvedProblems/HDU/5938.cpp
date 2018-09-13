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

const int MAX = 1e3 + 10;
const int N = 1e3 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1007;
const double EPS = (double)1e-10;
const LL LINF = 0x3f3f3f3f3f3f3f;
const int LMON[15] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
const int CMON[15] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
const int diro[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
const int dirt[6][3] = {{0,0,1},{0,0,-1},{1,0,0},{-1,0,0},{0,1,0},{0,-1,0}};

int main()
{
#ifdef LOCAL
	//~ fli
	//~ flo
#endif	//LOCAL

	int T;
	sfi(T);
	rep(kase, 1, T)
	{
		char tmp[MAX];
		sfs(tmp);
		int len = strlen(tmp);
		int s[MAX] = {0};
		rep(i, 1, len)
			s[i] = tmp[i - 1] - '0';
		ll ans = 0;
		if(len == 5)
		{
			ans = s[1] + s[2] - s[3] * s[4] / s[5];
		}
		else if(len == 6)
		{
			ll tmp = (s[1] * 10 + s[2]) + s[3] - s[4] * s[5] / s[6];
			ans = max(ans, tmp);
			tmp = s[1] + (s[2] * 10 + s[3]) - s[4] * s[5] / s[6];
			ans = max(ans, tmp);
			tmp = s[1] + s[2] - (s[3] * 10 + s[4]) * s[5] / s[6];
			ans = max(ans, tmp);
			tmp = s[1] + s[2] - s[3] * (s[4] * 10 + s[5]) / s[6];
			ans = max(ans, tmp);
			tmp = s[1] + s[2] - s[3] * s[4] / (s[5] * 10 + s[6]);
			ans = max(ans, tmp);
		}
		else
		{
			ll tmp = 0, first = 0;
			rep(i, 1, len - 4)
				first = first * 10 + s[i];
			tmp = first + s[len - 3] - s[len - 2] * s[len - 1] / s[len];
			ans = tmp;
			first = 0;
			rep(i, 2, len - 3)
				first = first * 10 + s[i];
			tmp = s[1] + first - s[len - 2] * s[len - 1] / s[len];
			ans = max(ans, tmp);
		}
		printf("Case #%d: %lld\n", kase, ans);
	}
	return 0;
}