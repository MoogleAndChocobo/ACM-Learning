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

using namespace std;

typedef long long LL;

const int MAX = 1e5 + 10;
const int N = 65536;
const int INF = 0x3f3f3f3f;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfs(a) scanf("%s", a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define pb(a) push_back(a)

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
#endif	//LOCAL

	//~ ios::sync_with_stdio(0);
	//~ cin.tie(0);

	LL m, n;
	while(~scanf("%lld%lld", &m, &n))
	{
		if(!m && !n)
			break;
		printf("%lld\n", m + (n - 2));
	}
	return 0;
}