#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <cmath>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define mem(a) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define sfu(a) scanf("%llu", &a)

const int MAX = 1e3 + 5;
const double PI = acos(-1.0);
const double EPS = 1e-5;

int main()
{
	
	double r, v1, v2;
	while(~scanf("%lf%lf%lf", &r, &v1, &v2))
	{
		if(v2 / v1 < PI + 1)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}