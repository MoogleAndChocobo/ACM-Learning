#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <vector>

using namespace std;

typedef long long LL;
typedef long long ll;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define mem(a) memset(a, 0, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)

const int MAX = 1e3 + 5;

int main()
{
	int T;
	sfi(T);
	rep(kase, 1, T)
	{
		LL m, n, k;
		scanf("%lld%lld%lld", &k, &m, &n);
		LL ans = 0;
		if(k <= 6)
			ans = (15 - k) * k / 2;
		else
			ans = 27 + 8 * (k - 6);
		if(ans + m >= n)
			puts("Yes");
		else
			puts("No");

	}
	return 0;
}