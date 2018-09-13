#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%lld", a)

const int MAX = 1e3 + 5;

bool vis[MAX];

int go(int k, int now, int sum, bool f)
{
	int cnt = 0;
	while(true)
	{
		if(!vis[now])
		{
			cnt++;
			if(cnt >= k)
				break;
		}
		if(f)
			++now > sum ? now -= sum : now = now;
		else
			--now < 1 ? now += sum : now = now;
	}
	return now;
}

void print(int x)
{
	printf("%s", x < 10 ? "  " : " ");
	printf("%d", x);
}

int main()
{
	int sum, k, n;
	while(~scanf("%d%d%d", &sum, &k, &n))
	{
		if(!sum && !k && !n)
			break;
		
		k %= sum, n %= sum;
		if(!k)
			k = sum;
		if(!n)
			n = sum;
		
		mem(vis);
		int a = 1, b = sum, cnt = 0;
		
		bool f = false;
		while(cnt < sum)
		{
			if(f)
				putchar(',');
			f = true;
			
			a = go(k, a, sum, true);
			b = go(n, b, sum, false);
			if(a == b)
				print(a), ++cnt;
			else
				print(a), print(b), cnt += 2;
			vis[a] = vis[b] = true;
		}
		putchar('\n');
	}
	return 0;
}