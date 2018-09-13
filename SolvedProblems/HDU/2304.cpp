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
	int T;
	sfi(T);
	rep(kase, 1, T)
	{
		int n;
		sfi(n);
		int ans = 0;
		rep(i, 1, n)
		{
			int tmp;
			sfi(tmp);
			ans += tmp;
		}
		printf("%d\n", ans - (n - 1));
	}
	return 0;
}