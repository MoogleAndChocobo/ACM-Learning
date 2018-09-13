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
	LL n, w, d, sum;
	while(~scanf("%lld%lld%lld%lld", &n, &w, &d, &sum))
	{
		LL ans = ((n * (n - 1) / 2) * w - sum) / d;
		if(!ans)
			ans = n;
		printf("%lld\n", ans);
	}
	return 0;
}