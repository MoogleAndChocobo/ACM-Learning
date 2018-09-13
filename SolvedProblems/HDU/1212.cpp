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

const int MAX = 1e3 + 5;



int main()
{
	char s[MAX];
	LL mod;
	while(~scanf("%s%lld", s, &mod))
	{
		int len = strlen(s);
		int num[MAX] = {0};
		int cnt = 0;
		dow(i, len - 1, 0)
			num[++cnt] = s[i] - '0';
		int lmt = cnt / 9;
		cnt = 0;
		LL store[MAX] = {0};
		rep(i, 1, lmt)
		{
			LL number = 0;
			dow(j, 9, 1)
				number = number * 10 + (LL)num[(i - 1) * 9 + j];
			store[++cnt] = number;
		}
		if(len % 9)
		{
			cnt++;
			LL number = 0;
			dow(i, len, len / 9 * 9 + 1)
				number = number * 10 + (LL)num[i];
			store[cnt] = number;
		}
		//~ rep(i, 1, cnt)
			//~ printf("%lld ", store[i]);
		//~ putchar('\n');
		
		LL ans = 0;
		LL pre = 1;
		rep(i, 1, cnt)
		{
			LL now = 0;
			now = ((pre % mod) * (store[i] % mod)) % mod;
			pre *= 1e9;
			pre %= mod;
			ans += now;
			ans %= mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}