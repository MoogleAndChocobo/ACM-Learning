#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cctype>
#include <queue>
#include <set>
#include <map>
#include <stack>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define sfs(a) scanf("%s", a)
#define sfi(a) scanf("%d", &a)
#define sfu(a) scanf("%llu", &a)
#define pb(a) push_back(a)
#define mem(a) memset(a, 0, sizeof(a))

const int MAX = 1e3 + 5;
const LL N = 5e5;
const LL MOD = 1e4;
const double eps = 1e-9;
const int INF = 0x3f3f3f3f;

int main()
{
	int s[MAX] = {0};
	rep(i, 1, 5)
		sfi(s[i]);
	sort(s + 1, s + 6);
	dow(i, 5, 1)
	{
		printf("%d", s[i]);
		if(i != 1)
			putchar(' ');
		else
			putchar('\n');
	}
	return 0;
}
