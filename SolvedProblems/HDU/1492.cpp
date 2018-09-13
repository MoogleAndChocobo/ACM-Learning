#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define mem(a) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define sfu(a) scanf("%llu", &a)

const int MAX = 1e3 + 5;

int main()
{
	
	ULL n;
	while(~sfu(n) && n)
	{
		ULL c2, c3, c5, c7;
		c2 = c3 = c5 = c7 = 0;
		while(n != 1)
		{
			if(n % 2 == 0)
				n /= 2, c2++;
			if(n % 3 == 0)
				n /= 3, c3++;
			if(n % 5 == 0)
				n /= 5, c5++;
			if(n % 7 == 0)
				n /= 7, c7++;
		}
		printf("%llu\n", (c2 + 1) * (c3 + 1) * (c5 + 1) * (c7 + 1));
	}
	return 0;
}