#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cctype>
#include<vector>
#include<queue>
#include<set>
#include<map>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

//const int MAX = 1e5 + 10;
const int N = 1e3;
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define sfs(a) scanf("%s", a)

const int MAX=2e5+5;
bool vis[MAX];
int a[MAX];

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
#endif	//LOCAL

	int ans = 0;
	int n;
	sfi(n);
	rep(i, 1, n)
		sfi(a[i]);
	dow(i, n, 1)
	{
		if(!vis[i])
		{
			vis[i] = true;
			ans++;
			int now = i;
			while(now != 0)
			{
				now = a[now];
				vis[now] = true;
			}
		}
	}
	printf("%d\n", ans);
	
	return 0;
}