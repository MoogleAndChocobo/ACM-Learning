#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i; 
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a) memset(a, b, sizeof(a))
#define pb(a) push_back(a)
#define all(a) a.begin(),a.end()
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define sfd(a) scanf("%lf", &a)
#define sync ios::sync_with_stdio(false);cin.tie(0);

const int MAX = 1e5 + 5;
const int N = 1e3;


int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
	//~ freopen("out.txt", "w", stdout);
#endif

	LL n;
	while(~sfl(n))
	{
		int cnt = 0;
		while(n)
		{
			cnt++;
			LL tmp = n;
			LL mx = 0;
			while(tmp)
			{
				mx = max(mx, tmp % 10);
				tmp /= 10;
			}
			n -= mx;
		}
		printf("%d\n", cnt);
	}
	return 0;
}