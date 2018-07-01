#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstring>
#include <cstdlib>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <deque>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef unsigned U;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define sfs(a) scanf("%s", &a)
#define sfu(a) scanf("%llu", &a)
#define pb(a) push_back(a)
#define all(a) a.begin(),a.end()

const int MAX = 1e3 + 10;
const LL MOD = 998244353;

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin );
	//~ freopen("out.txt", "w", stdout);
#endif

	int n;
	while(~sfi(n))
	{
		int ans = n / 100;
		n %= 100;
		ans += n / 20;
		n %= 20;
		ans += n / 10;
		n %= 10;
		ans += n / 5 + n % 5;
		printf("%d\n", ans);		
	}
	
	return 0;
}
