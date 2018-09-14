#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <cctype>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define sfd(a) scanf("%lf", &a)
#define pb(a) push_back(a)

const int MAX = 5e5 + 5;

LL s[MAX] = {0};
char rec[MAX];

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
	//~ freopen("out.txt", "w", stdout);
#endif

	int n;
	sfi(n);
	rep(i, 0, n - 1)
		sfl(s[i]);
	sfs(rec);
	
	LL ans = 0;
	rep(i, 0, n - 1)
	{
		if(rec[i] == 'B')
			ans += s[i];
	}
	
	LL tmp = ans;
	
	LL sum = ans;
	rep(i, 0, n - 1)
	{
		if(rec[i] == 'A')
			sum += s[i];
		else
			sum -= s[i];
		ans = max(ans, sum);
	}
	
	sum = tmp;
	dow(i, n - 1, 0)
	{
		if(rec[i] == 'A')
			sum += s[i];
		else
			sum -= s[i];
		ans = max(ans, sum);
	}
	printf("%lld\n", ans);
	return  0;
}