#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <vector>
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

const int MAX = 1e3 + 10;

int main()
{
	int n;
	sfi(n);
	int s[MAX] = {0};
	rep(i, 1, n)
		sfi(s[i]);
	
	int ans = 0x3f3f3f3f;
	rep(i, 1, n)
	{
		int sum = 0;
		rep(j, i, i + n - 1)
		{
			int idx = j;
			if(idx > n)
				idx -= n;
			sum += s[idx];
			ans = min(ans, abs(sum - (360 - sum)));
		}
	}
	printf("%d\n", ans);
	return 0;
}