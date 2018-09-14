#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <iostream>
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

const int MAX = 1e5 + 5;
const int N = 1e5;

LL getlen(LL x)
{
	if(x < 10)
		return 1;
	if(x < 100)
		return 2;
	if(x < 1000)
		return 3;
	if(x < 10000)
		return 4;
	if(x < 100000)
		return 5;
	return 6;
}

LL re(LL x)
{
	LL ans = 0;
	LL len = getlen(x);
	while(len--)
	{
		ans += pow(10, len) * (x % 10);
		x /= 10;
	}
	return ans;
}

int main()
{
	LL k, mod;
	scanf("%lld%lld", &k, &mod);
	LL ans = 0;
	for(LL i = 1; i <= k; i++)
	{
		ans += i * pow(10, getlen(i)) + re(i);
		ans %= mod;
	}
	printf("%lld\n", ans);
	return 0;
}