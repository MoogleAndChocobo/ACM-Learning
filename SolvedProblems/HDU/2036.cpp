#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define mem(a) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)

const int MAX = 1e3 + 5;

struct Node
{
	double x, y;
} s[MAX];

double area(int  a)
{
	int b = a - 1;
	return (s[b].x * s[a].y - s[a].x* s[b].y) - (s[1].x * s[a].y - s[a].x* s[1].y) + (s[1].x * s[b].y - s[b].x* s[1].y);
}

int main()
{
	int n;
	while(~sfi(n) && n)
	{
		rep(i, 1, n)
			scanf("%lf%lf", &s[i].x, &s[i].y);
		double ans = 0;
		rep(i, 3, n)
		{
			ans += 1.0 / 2.0 * area(i);
		}
		printf("%.1lf\n", ans);
	}
	return 0;
}