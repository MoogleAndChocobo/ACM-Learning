//~ #define LOCAL

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<iostream>
#include<vector>
#include<sstream>
#include<map>
#include<set>
#include<cmath>
#include<cctype>
#include<functional>
#include<ctime>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LF;

const int MAX = 1e4 + 10;
const int N = 1e3;
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f;

#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%ld", &a)
#define sfs(a) scanf("%s", a)
#define sfc(a) getchar(a)
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))

struct Node
{
	int cost, need;
	friend bool operator <(Node a, Node b)
	{
		if(a.need != b.need)
			return a.need < b.need;
		else
			return a.cost < b.cost;
	}
};

int main()
{
	
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	int n;
	int cnt = 0;
	while(~scanf("%d", &n) && n)
	{
		Node s[MAX];
		rep(i, 1, n)
		{
			scanf("%d%d", &s[i].cost, &s[i].need);
		}
		sort(s + 1, s + n + 1);
		int ans = 0, now = 0;
		dow(i, n, 1)
		{
			now += s[i].cost;
			ans = max(ans, now + s[i].need);
		}
		printf("Case %d: %d\n", ++cnt, max(ans, now));
	}
	return 0;
}