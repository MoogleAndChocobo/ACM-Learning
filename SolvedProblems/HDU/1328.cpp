#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <cctype>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define sfs(a) scanf("%s", a)

const int MAX = 2e4 + 5;
const int N = 1e2 + 5;
const int MOD = 1e9 + 7;

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
	//~ freopen("out.txt", "w", stdout);
#endif

	int T;
	sfi(T);
	rep(kase, 1, T)
	{
		char s[N];
		sfs(s);
		printf("String #%d\n", kase);
		int len = strlen(s);
		rep(i, 0, len - 1)
		{
			putchar(s[i] == 'Z' ? 'A' : s[i] + 1);
		}
		putchar('\n');
		putchar('\n');
	}
	return 0;
}