#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cctype>
#include<iostream>
#include<iomanip>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

typedef long long ll;
#define int long long
const int MAX = 5e5 + 5;

ll pre[33][MAX];

const int MOD = 1e9;

signed main()
{
	int T;
	scanf("%lld", &T);
	while(T--)
	{
		memset(pre[0], 0, sizeof(ll) * MAX);

		ll n, m;
		scanf("%lld %lld", &n, &m);

        for(int i = 1; i <= n; i++)
		{
            scanf("%lld", &pre[0][i]);
		}

		sort(pre[0] + 1, pre[0] + n + 1);

		for(int i = 1; i <= n; i++)
		{
			for(int j = 1;j <= 32; j++)
				pre[j][i] = pre[j][i - 1] + pre[0][i] / j;
		}
        ll ans = 0;
        for(int i = 1; i <= m; i++)
		{
			ll p, tp, now = 0;
			scanf("%lld", &p);
			tp = p;
			int last = 1;
			for(int j = 1; 1; j++)
			{
				int pos = upper_bound(pre[0] + 1, pre[0] + n + 1, p) - pre[0];
				now = (now + pre[j][pos - 1] - pre[j][last - 1]) % MOD;
				if(p > MOD) break;
				p = p * tp;
				last = pos;
			}
			ans = (ans + (now * i) % MOD) % MOD;
		}
		printf("%lld\n", (ans + MOD) % MOD);
	}

}