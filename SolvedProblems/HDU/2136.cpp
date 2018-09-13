

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <list>
#include <cctype>
#include <ctime>
#include <functional>
#include <cmath>

using namespace std;

typedef unsigned U;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> pii;

const int MAX = 1e6 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e6;
const LL LINF = 0x3f3f3f3f3f3f3f;

#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfc(a) scanf("%c", &c)
#define sfs(a) scanf("%s", a)
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))

bool isprime[MAX];
int prime[MAX];
int ans[MAX];

void init(void)
{
	int cnt = 0;
	mst(isprime, true);
	isprime[0] = isprime[1] = false;
	rep(i, 2, N)
	{
		if(isprime[i])
			prime[++cnt] = i;
		for(int j = 1; j <= cnt && i * prime[j] <= N; j++)
		{
			isprime[i * prime[j]] = false;
			if(i % prime[j] == 0)
				break;
		}
	}
	return;
}

void solve(void)
{
	int cnt = 0;
	mem(ans);
	rep(i, 2, N)
	{
		if(isprime[i])
		{
			cnt++;
			for(int j = i; j <= N; j += i)
				ans[j] = cnt;
		}
	}
	return;
}

int main()
{
	
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif	//LOCAL

	//ios::sync_with_stdio(false);
	//cin.tie(0);

	init();
	solve();
	int n;
	while(~sfi(n))
	{
		printf("%d\n", ans[n]);
	}
	return 0;
}