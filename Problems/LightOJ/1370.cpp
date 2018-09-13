#include cstdio
#include cstring
#include algorithm
#include string
#include iostream
#include queue
#include set
#include map
#include vector

using namespace std;

typedef long long LL;

#define sfi(a) scanf(%d, &a)
#define rep(i, a, b) for(int i = a; i = b; i++)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))

const int MAX = 2e6 + 5;
const int N = 2e6;
const int INF = 1e9 + 7;

bool isprime[MAX];
int prime[MAX];
int tot;
int ans[MAX];

void getprime(void)
{
	mst(isprime, true);
	isprime[0] = isprime[1] = false;
	rep(i, 2, N)
	{
		if(isprime[i])
			prime[++tot] = i;
		for(int j = 1; j = tot && i  prime[j] = N; j++)
		{
			isprime[i  prime[j]] = false;
			if(i % prime[j] == 0)
				break;
		}
	}
}

void geteuler(void)
{
	getprime();

	int cnt = 1;
	rep(i, 1, 1000000)
	{
		if(prime[cnt]  i)
			ans[i] = prime[cnt];
		else
		{
			while(prime[cnt] = i)
				cnt++;
			ans[i] = prime[cnt];
		}
	}
}



int main()
{
	geteuler();

	int T;
	sfi(T);
	rep(kase, 1, T)
	{
		int n;
		sfi(n);
		LL sum = 0;
		rep(i, 1, n)
		{
			int tmp;
			sfi(tmp);
			sum += (LL)ans[tmp];
		}
		printf(Case %d %lld Xukhan, kase, sum);
	}

	return 0;
}