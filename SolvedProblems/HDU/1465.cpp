#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAX = 1e3 + 10;
const int N = 1e3;
const int MOD = 1e9 + 7;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define sfs(a) scanf("%s", a)

LL s[MAX];

void init(void)
{
	s[1] = 0;
	s[2] = 1;
	rep(i, 3, 20)
		s[i] = (i - 1) * (s[i - 1] + s[i - 2]);
}

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
#endif	//LOCAL

	init();

	int n;
	while(~sfi(n))
	{
		printf("%lld\n", s[n]);
	}
	return 0;
}