#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define sfl(a) scanf("%lld", &a)

LL m, n, k;

int main()
{
	while(~scanf("%lld%lld%lld", &m, &n, &k))
	{
		LL ans = -1;
		if(k > n - 1 + m - 1)
			;
		else if(k >= max(m, n))
			ans = min(m, n) / (k + 1 - (max(m, n) - 1));
		else
			ans = max(max(n / (k + 1) * m, m / (k + 1) * n), ans);
		printf("%lld\n", ans);
	}
	return 0;
}