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

const int MAX = 1e3 + 10;
const int N = 1e3;
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f;

#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfu(a) scanf("%llu", &a)
#define sfd(a) scanf("%ld", &a)
#define sfs(a) scanf("%s", a)
#define sfc(a) getchar(a)
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))

int main()   
{
	
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	double pre, n;
	while(scanf("%lf%lf", &pre, &n) != EOF)
	{
		int sum = pre + n;
		double ans = 0;
		rep(i, 1, pre - 1)
		{
			double pos = (double)i / pre * sum;
			ans += fabs(pos - floor(pos + 0.5)) / sum;
		}
		printf("%.4lf\n", ans * 10000);
	}
	return 0;
}