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

int mp[MAX], s[MAX];

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
	//~ freopen("out.txt", "w", stdout);
#endif

	int n;
	sfi(n);
	rep(i, 1, n)
		sfi(s[i]), mp[s[i]] = i;
	int q;
	sfi(q);
	while(q--)
	{
		int opr, x, y;
		scanf("%d%d%d", &opr, &x, &y);
		if(opr == 2)
		{
			swap(s[x], s[y]);
			mp[s[x]] = x;
			mp[s[y]] = y;
			//~ rep(i, 1, n)
				//~ printf("%d ", mp[i]);
			//~ putchar('\n');
		}
		else
		{
			int cnt = 1;
			rep(i, x, y - 1)
			{
				if(mp[i] > mp[i + 1])
					cnt++;
			}
			printf("%d\n", cnt);
		}
	}
	return 0;
}