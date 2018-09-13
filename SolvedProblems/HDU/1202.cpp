//~ #define LOCAL

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<iostream>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<list>
#include<cctype>
#include<ctime>
#include<functional>
#include<cmath>

using namespace std;

typedef unsigned U;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> pii;

const int MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const LL LINF = 0x3f3f3f3f3f3f3f;

#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfc(a) scanf("%c", &c)
#define sfs(a) scanf("%s", a)
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))

double gt(double n)
{
	if(n == -1)
		return -1;
	if(n < 60)
		return 0;
	else if(n < 70)
		return 1;
	else if(n < 80)
		return 2;
	else if(n < 90)
		return 3;
	return 4;
}

int main()
{
	
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	//ios::sync_with_stdio(false);
	//cin.tie(0);

	int n;
	while(~sfi(n))
	{
		double suma = 0, sumb = 0;
		double s, p;
		while(n--)
		{
			scanf("%lf%lf", &s, &p);
			int tmp = gt(p);
			if(gt(p) == -1)
				continue;
			suma += s;
			sumb += s * tmp;
		}
		if(suma)
		{
			double ans = sumb / suma;
			printf("%.2lf\n", ans);
		}
		else
			printf("-1\n");
	}
	return 0;
}