#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<string>
#include<set>
#include<map>
#include<queue>
#include <functional>

using namespace std;

typedef long long ll;
typedef long long LL;
typedef unsigned long long ULL;

const int MAX = 1e5 + 10;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define sfl(a) scanf("%lld", &a)
#define mem(a) memset(a, 0, sizeof(a))

ll s[MAX];

int main()
{
	int T;
	sfi(T);
	rep(kase, 1, T)
	{
		mem(s);
		int n, k;
		scanf("%d%d", &n, &k);
		ll sum = 0;
		rep(i, 1, n)
		{
			sfl(s[i]);
			sum += s[i];
		}
		if(sum % k)
		{
			printf("Case #%d: -1\n", kase);
			continue;
		}

		ll now = sum / k;
		ll tmp = 0, ans = 0, cnt = 0;
		int idx = 0;
		bool check = false;
		bool flag = true;
		while(cnt != k)
		{
			//~ cout << tmp << endl;
			if(tmp == now)
			{
				tmp = 0;
				cnt++;
				check = false;
			}
			else if(tmp > now)
			{
				tmp -= now;
				cnt++;
				ans++;
				check = true;
			}
			else if(tmp < now)
			{
				if(idx == n)
				{
					flag = false;
					break;
				}
				tmp += s[++idx];
				if(check)
					ans++;
				check = true;
			}
		}
		printf("Case #%d: ", kase);
		printf("%lld\n", flag ? ans : -1);
	}
	return 0;
}