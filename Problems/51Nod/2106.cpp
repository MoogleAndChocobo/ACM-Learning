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

map<int,int> mp;
set<int> s;

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
	//~ freopen("out.txt", "w", stdout);
#endif

	int n;
	sfi(n);
	rep(i, 1, n)
	{
		int tmp;
		sfi(tmp);
		mp[tmp]++;
		s.insert(tmp);
	}
	for(set<int>::iterator it = s.begin(); it != s.end(); ++it)
	{
		if(mp[*it] % 2 == 1)
			printf("%d\n", *it);
	}
	return 0;
}
