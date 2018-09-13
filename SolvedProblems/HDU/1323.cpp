//~ #define LOCAL

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<iostream>
#include<cmath>
#include<cctype>
#include<vector>
#include<set>
#include<queue>

using namespace std;

typedef long long LL;

const int MAX = 1e5 + 10;
const int N = 6e4;
const int INF = 0x3f3f3f3f;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define pb(a) push_back(a)

int s[MAX];

void init(void)
{
	rep(i, 1, N)
		s[i] = 1;
	rep(i, 2, N)
	{
		for(int j = i + i; j <= N; j += i)
		{
			s[j] += i;
		}
	}
}

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
#endif	//LOCAL

	init();

	puts("PERFECTION OUTPUT");
	int n;
	while(~sfi(n) && n)
	{
		printf("%5d  ", n);
		if(s[n] == n)
			puts("PERFECT");
		else if(s[n] > n)
			puts("ABUNDANT");
		else
			puts("DEFICIENT");
	}
	puts("END OF OUTPUT");
	return 0;
}