#include<cstdio>
#include<cstring>

using namespace std;

const int MAX = 3e6 + 10;
const int N = 1e6+ 10;


struct GetEuler
{
	int prime[MAX], euler[MAX];
	bool isprime[MAX];
	int tot;

	void init(void)
	{
		memset(isprime, true, sizeof(isprime));
		memset(prime, 0, sizeof(prime));
		memset(euler, 0, sizeof(euler));
		tot = 0;
	}

	void getprime(int n)
	{
		isprime[0] = isprime[1] = false;
		for(int i = 2; i <= n; i++)
		{
			if(isprime[i])
				prime[++tot] = i;
			for(int j = 1; j <= tot && i * prime[j] <= n; j++)
			{
				isprime[i * prime[j]] = false;
				if(i % prime[j] == 0)
					break;
			}
		}
	}

	void solve(int n)
	{
		init();

		getprime(2 * n);

		euler[1] = 1;
		for(int i = 2; i <= n; ++i)
		{
			if(isprime[i])
			{
				euler[i] = i - 1;
				continue;
			}
			for(int j = 1; j <= tot; ++j)
			{
				if(i % prime[j])
					continue;
				if(i / prime[j] % prime[j])
					euler[i] = euler[i / prime[j]] * (prime[j] - 1);
				else
					euler[i] = euler[i / prime[j]] * prime[j];
				break;
			}
		}
	}
};

GetEuler g;
long long res[N];
int main()
{
	g.solve(N);
	for(int i = 2; i < N-1; i++)
	{
		res[i]=res[i-1]+g.euler[i];
	}
	int n;
	while(~scanf("%d",&n)&&n)
	{
		printf("%lld\n",res[n]);
	}
	return 0;

}

/*
	clang++ -std=c++11 2333.cpp
	./a.out

*/