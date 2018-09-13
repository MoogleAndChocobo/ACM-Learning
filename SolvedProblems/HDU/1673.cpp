#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAX = 1e4 + 10;
const int N = 1e3;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define sfs(a) scanf("%s", a)

const int MON[MAX] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
#endif	//LOCAL

	int T;
	sfi(T);
	rep(kase, 1, T)
	{
		int n;
		sfi(n);
		int s[MAX] = {0};
		rep(i, 1, n)
			sfi(s[i]);
		sort(s + 1, s + n + 1);
		printf("%d\n", 2 * (s[n] - s[1]));
	}
	return 0;
}