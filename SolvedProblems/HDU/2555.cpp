#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <cctype>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof(a))
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)

const int MAX = 2e4 + 5;
const int N = 1e2 + 5;

struct Node
{
	int x1, y1, x2, y2;
};

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
	//~ freopen("out.txt", "w", stdout);
#endif

	int m, n;
	while(~scanf("%d%d", &m, &n))
	{
		Node a[MAX], b[MAX];
		int ans[MAX] = {0};
		rep(i, 1, m)
			scanf("%d%d", &a[i].x1, &a[i].y1);
		rep(i, 1, n)
			scanf("%d%d%d%d", &b[i].x1, &b[i].y1, &b[i].x2, &b[i].y2);
		rep(i, 1, m)
		{
			rep(j, 1, n)
				if(a[i].x1 >= b[j].x1 && a[i].x1 <= b[j].x2 && a[i].y1 >= b[j].y1 && a[i].y1 <= b[j].y2)
				{
					ans[i] = (b[j].x2 - b[j].x1 + b[j].y2 - b[j].y1) * 2;
					break;
				}
		}
		sort(ans + 1, ans + m + 1);
		dow(i, m, 1)
			printf("%d\n", ans[i]);
	}
	return 0;
}