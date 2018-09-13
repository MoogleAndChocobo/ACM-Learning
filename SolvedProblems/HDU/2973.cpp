#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)

const int MAX = 4e6 + 10;
const int N = 4e6;

bool isprime[MAX];
int prime[MAX], ans[MAX];
int tot;

void init()
{
	mst(isprime, true);
	isprime[0] = isprime[1] = false;
	rep(i, 2, N)
	{
		if(isprime[i])
		{
			prime[++tot] = i;
		}
		for(int j = 1; j <= tot && i * prime[j] <= N; j++)
		{
			isprime[i * prime[j]] = false;
			if(i % prime[j] == 0)
				break;
		}
	}

	const int LMT = 1e6;

	int order = 1;
	int cnt = 0;
	for(int i = 10; i <= 3 * LMT + 7; i += 3)
	{
		if(isprime[i])
			cnt++;
		ans[order++] = cnt;
	}

}


int main()
{
	init();

	int T;
	sfi(T);
	rep(kase, 1, T)
	{
		int n;
		sfi(n);
		printf("%d\n", ans[n]);
	}
	return 0;
}