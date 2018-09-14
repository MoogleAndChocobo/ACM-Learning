#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define sfs(a) scanf("%s", a)
#define mem(a) memset(a, 0, sizeof(a))

const int MAX = 1e5 + 10;

LL s[MAX];

int main()
{
	LL n, x, k;
	scanf("%lld%lld%lld", &n, &x, &k);
	rep(i, 1, n)
		sfl(s[i]);
	sort(s + 1, s + 1 + n);
	LL ans = 0;
	rep(i, 1, n)
	{
		LL times = k;
		if(s[i] % x == 0 && s[i] / x)
			times--;
		LL mn = (s[i] / x + times) * x;
		LL mx = (s[i] / x + times) * x + x;
		if(!k)
			mn = s[i];
		int num = lower_bound(s + 1, s + n + 1, mx) - lower_bound(s + 1, s + n + 1, mn);
		ans += (LL)num;
	}
	printf("%lld\n", ans);
	return 0;
}