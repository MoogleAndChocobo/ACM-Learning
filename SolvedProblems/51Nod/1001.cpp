#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <functional>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define sfd(a) scanf("%l", &a)
#define sfu(a) scanf("%llu", &a)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define pb(a) push_back(a)

const int MAX = 5e4 + 50;
const int N = 1e3;
const int MOD = 1e9 + 7;

struct Node
{
	int x, y;
	Node(int xx, int yy):x(xx), y(yy){}
};

vector<Node> vec;
int s[MAX];
bool vis[MAX];

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
	//~ freopen("out.txt", "r" , stdout);
#endif

	int k, n;
	scanf("%d%d", &k, &n);
	rep(i, 1, n)
		sfi(s[i]);
	sort(s + 1, s + n + 1);
	
	rep(i, 1, n)
	{
		if(!vis[i])
		{
			int now = k - s[i];
			int idx = lower_bound(s + 1, s + n + 1, now) - s;
			if(idx <= n && s[idx] == now && now != s[i])
			{
				vis[i] = vis[idx] = true;
				vec.pb(Node(s[i], now));
			}
		}
	}
	int len = vec.size();
	rep(i, 0, len - 1)
		printf("%d %d\n", vec[i].x, vec[i].y);
	if(!len)
	{
		puts("No Solution");
	}
	return 0;
}
