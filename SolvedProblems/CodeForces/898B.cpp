#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cctype>
#include <iostream>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i > =b; --i)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define sfs(a) scanf("%s", a)
#define pb(a) push_back(a)
#define all(a) a.begin(),a.end()

const int MAX = 1e5 + 5;
const int INF = 1e5;

int main()
{
	LL n, a, b;
	while(~scanf("%lld%lld%lld", &n, &a, &b))
	{
		for(LL i = 0; i <= 10000005; i++)
		{
			if((n - i * a) % b == 0 && (n - i * a) / b >= 0)
			{
				puts("YES");
				printf("%lld %lld\n", i, (n - i * a) / b);
				break;
			}
			if(i == 10000005)
				puts("NO");
		}
	}
	return 0;
}