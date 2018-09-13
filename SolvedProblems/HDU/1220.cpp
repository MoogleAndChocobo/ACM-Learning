#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define mem(a) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)

const int MAX = 1e3 + 5;



int main()
{
	LL n;
	while(~sfl(n))
	{
		if(n == 1)
		{
			puts("0");
			continue;
		}
		LL three = n * n * n;
		LL two = n * n;
		LL tmp = three - 4;
		LL cnt = three - 3;
		for(LL i = 2; i < n; i++)
		{
			tmp += --cnt - 1;
		}
		tmp += cnt - 1;
		//~ printf("tmp = %lld\n", tmp);
		
		cnt = tmp;
		for(LL i = 2; i < n; i++)
		{
			tmp += cnt - n * (i - 1) * n;
		}
		tmp += cnt - n * (n - 1) * n + n;
		
		//~ printf("tmp = %lld\n", tmp);
		LL ans = tmp;
		for(LL i = 2; i < n; i++)
		{
			ans += tmp - two * (i - 1) * two;
			//~ printf("ans = %lld\n", ans);
		}
		//~ printf("::ans = %lld\n", ans);
		ans += tmp - two * (n - 1) * two + two;
		
		printf("%lld\n", ans);
	}
	return 0;
}