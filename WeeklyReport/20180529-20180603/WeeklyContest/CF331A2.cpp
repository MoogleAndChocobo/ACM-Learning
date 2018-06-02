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

const int MAX = 3e5 + 5;
const int N = 1e3;

LL s[MAX];
LL rec[MAX];
map<LL,vector<int> > mp;
map<LL, bool> vis;

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
	//~ freopen("out.txt", "w", stdout);
#endif

	int n;
	sfi(n);
	LL sum = 0;
	rep(i, 1, n)
	{
		sfl(s[i]);
		mp[s[i]].pb(i);
		if(s[i] > 0)
			sum += s[i];
		rec[i] = sum;
	}

	LL mx = -10000000000000000;
	int resa = 1, resb = n;
	rep(i, 1, n)
	{
		if(vis[s[i]])
			continue;
		vis[s[i]] = true;
		vector<int> vec = mp[s[i]];
		int st = i, en = vec[vec.size() - 1];
		if(st == en)
			continue;
		//~ printf("st = %d en = %d\n", st, en);
		//~ printf("rec[st] = %lld res[en] = %lld\n", rec[st], rec[en]);
		LL now = s[i] > 0 ? 0 : s[i] * 2;
		now += rec[en] - rec[st - 1];
		
		//~ printf("now = %lld\n", now);
		if(now > mx)
		{
			mx = now;
			resa = st;
			resb = en;
		}
	}
	
	vector<int> del;
	sum = s[resa] * 2;
	rep(i, 1, resa - 1)
		del.pb(i);
	rep(i, resa + 1, resb - 1)
		if(s[i] > 0)
			sum += s[i];
		else
			del.pb(i);
	rep(i, resb + 1, n)
		del.pb(i);
	
	//~ printf("resa = %d resb = %d\n", resa, resb);
	int len = del.size();
	printf("%lld %d\n", sum, len);
	rep(i, 0, len - 1)
	{
		printf("%d", del[i]);
		putchar(i != len - 1 ? ' ' : '\n');
	}
	return 0;
}
