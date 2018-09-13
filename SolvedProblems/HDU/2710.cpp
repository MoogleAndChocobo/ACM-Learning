#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <cmath>
#include <cctype>

using namespace std;

typedef long long LL;

const int MAX = 2e4 + 10;
const int N = 2e4;

#define rep(i, a, b) for(int i = a; i <=b; i++)
#define dow(i, a, b) for(int i = a; i >=b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf"�� &a)
#define sfs(a) scanf("%s", a)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(a) a.begin(),a.end()
#define fli freopen("in.txt", "r", stdin);
#define flo freopen("out.txt", "w",stdout);
#define pb(a) push_back(a)
#define yes puts("yes")
#define no puts("no");
#define Yes puts("Yes")
#define No puts("No")
#define YES puts("YES")
#define NO puts("NO")

int s[MAX];
bool isprime[MAX];
int prime[MAX];
int tot;

void gtprime()
{
	mst(isprime, true);
	isprime[0] = isprime[1] = false;
	rep(i, 2, N)
	{
		if(isprime[i])
			prime[++tot] = i;
		for(int j = 1; j <= tot && i * prime[j] <= N; j++)
		{
			isprime[i * prime[j]] = false;
			if(i % prime[j] == 0)
				break;
		}
	}
}

void init()
{
	gtprime();

	rep(i, 1, tot)
	{
		for(int cnt = 1; cnt * prime[i] <= N; cnt++)
			s[cnt * prime[i]] = prime[i];
	}
}


int main()
{
#ifdef LOCAL
	//~ fli
	//~ flo
#endif	//LOCAL

	init();

	int n;
	while(~sfi(n))
	{
		int ans = 0;
		rep(i, 1, n)
		{
			int tmp;
			sfi(tmp);
			if(s[tmp] > s[ans])
				ans = tmp;
		}
		if(ans)
			printf("%d\n", ans);
		else
			printf("1\n");
	}
	return 0;
}