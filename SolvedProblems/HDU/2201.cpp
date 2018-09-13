#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cctype>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof(a))
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define pb(a) push_back(a)

const int MAX = 1e3 + 5;
const int N = 1e3;
const int INF = 0x3f3f3f3f;

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
#endif

	int n, k;
	while(~scanf("%d%d", &n, &k))
	{
		double ans = 1;
		rep(i, 1, k)
		{
			ans *= (double)(n - 1) / (double)n;
			n--;
		}
		printf("%.2lf\n", 1.0 / n * ans);
	}
	return 0;
}