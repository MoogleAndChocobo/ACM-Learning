#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cctype>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b)("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define sfs(a) scanf("%s", a)
#define sfi(a) scanf("%d", &a)

const int MAX = 1e6 + 5;
const LL N = 5e5;

LL ans[MAX];

void init()
{
	for(LL i = 1; i <= N; i++)
	{
		int cnt = 2;
		for(LL j = i * cnt; j <= N; j = i * cnt)
		{
			ans[j] += (LL)i;
			cnt++;
		}
	}
}

int main()
{
	init();
	
	int T;
	sfi(T);
	while(T--)
	{
		int n;
		sfi(n);
		printf("%lld\n", ans[n]);
	}
	return 0;
}