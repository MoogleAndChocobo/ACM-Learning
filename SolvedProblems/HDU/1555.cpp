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

	int m, n;
	while(~scanf("%d%d", &m, &n))
	{
		if(!m && !n)
			break;
		int cnt = 0;
		int step = 0;
		while(m)
		{
			cnt++;
			step++;
			m--;
			if(step == n)
			{
				m++;
				step = 0;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}