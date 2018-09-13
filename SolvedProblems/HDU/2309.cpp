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

	int n;
	while(~sfi(n) && n)
	{
		int sum = 0;
		int s[MAX] = {0};
		rep(i, 1, n)
		{
			sfi(s[i]);
			sum += s[i];
		}
		sort(s + 1, s + n + 1);
		sum -= s[1] + s[n];
		printf("%d\n", sum / (n - 2));
	}
	return 0;
}