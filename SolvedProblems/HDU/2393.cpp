#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%lld", a)
#define sfd(a) scanf("%lf", &a)

const double PI = acos(-1.);
const int MAX = 1e4 + 5;
const int N = 1e7;

bool check(LL a, LL b, LL c)
{
	return (a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a);
}

int main()
{

	int T;
	sfi(T);
	rep(kase, 1, T)
	{
		printf("Scenario #%d:\n", kase);
		LL a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		puts(check(a, b, c) ? "yes\n" : "no\n");
	}
	return 0;
}