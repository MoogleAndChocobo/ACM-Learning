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

LL s[MAX];

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
	//~ freopen("out.txt", "w", stdout);
#endif

	int n;
	sfi(n);
	rep(i, 1, n)
		sfl(s[i]);
	
	int resa = 1, resb = n;
	LL mx = -1000000000000000;
	rep(i, 1, n)
	{
		rep(j, i + 1, n)
		{
			if(s[j] == s[i])
			{
				LL sum = s[i] + s[j];
				rep(k, i + 1, j - 1)
				{
					if(s[k] >= 0)
						sum += s[k];
				}
				if(sum > mx)
				{
					resa = i, resb = j;
					mx = sum;
				}
			}
		}
	}
	
	vector<int> ans;
	LL summ = s[resa] + s[resb];
	rep(i, 1, resa - 1)
		ans.push_back(i);
	rep(i, resa + 1, resb - 1)
		if(s[i] < 0)
			ans.pb(i);
		else
			summ += s[i];
	rep(i, resb + 1, n)
		ans.pb(i);
		
	int len = ans.size();
	printf("%lld %d\n", summ, len);
	rep(i, 0, len - 1)
	{
		printf("%d", ans[i]);
		putchar(i != len - 1 ? ' ' : '\n');
	}
	return 0;
}
