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

const int MAX = 1e3 + 5;
const int N = 1e3;

LL gcd(LL a, LL b)
{
	if(a < b)
		swap(a, b);
	while(b)
	{
		LL tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

int main()
{
	int T;
	sfi(T);
	while(T--)
	{
		LL a, b;
		scanf("%lld%lld", &a, &b);
		if(gcd(a, b) == 1)
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}