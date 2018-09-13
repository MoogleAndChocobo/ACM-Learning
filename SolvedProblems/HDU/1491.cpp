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

const int MON[MAX] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
#endif	//LOCAL

	int cmp = 21;
	rep(i, 1, 9)
		cmp += MON[i];

	int T;
	sfi(T);
	while(T--)
	{
		int mon, day;
		scanf("%d%d", &mon, &day);
		int sum = day;
		rep(i, 1, mon - 1)
		{
			sum += MON[i];
		}
		if(sum == cmp)
			puts("It's today!!");
		else if(sum > cmp)
			puts("What a pity, it has passed!");
		else
			printf("%d\n", cmp - sum);
	}
	return 0;
}