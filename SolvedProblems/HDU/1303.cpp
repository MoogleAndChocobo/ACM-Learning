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

const int MAX = 1e3 + 10;
const int N = 1e3;
const int INF = 0x3f3f3f3f;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define pb(a) push_back(a)

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
#endif	//LOCAL

	int n;
	while(~sfi(n) && (n + 1))
	{
		set<int> s;
		s.insert(n);
		while(~sfi(n) && n)
		{
			s.insert(n);
		}
		int ans = 0;
		for(set<int>::iterator it = s.begin(); it != s.end(); it++)
		{
			if(s.find((*it) * 2) != s.end())
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}