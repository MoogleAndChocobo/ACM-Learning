#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <functional>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define sfd(a) scanf("%l", &a)
#define sfu(a) scanf("%llu", &a)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define pb(a) push_back(a)

const int MAX = 5e5 + 50;
const int N = 1e3;
const int MOD = 1e9 + 7;

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
	//~ freopen("out.txt", "r" , stdout);
#endif

	int n;
	while(~sfi(n))
	{
		int ans = 0;
		while(n)
		{
			ans += n / 5;
			n /= 5;
		}
		printf("%d\n", ans);
	}
	return 0;
}
