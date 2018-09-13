#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <vector>

using namespace std;

typedef long long LL;
typedef long long ll;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define mem(a) memset(a, 0, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)

const int MAX = 1e3 + 5;

int main()
{
	int h, u, d, f;
	while(~scanf("%d%d%d%d", &h, &u, &d, &f))
	{
		if(!h)
			break;
		bool flag = true;
		double dis = 0.;
		int day = 0;
		double v = u;
		while(dis < h)
		{
			//~ printf("%lf %lf %lf\n", v, dis, 100 - f);
			day++;
			dis += v;
			if(dis > h)
				break;
			dis -= d;
			v -= (double)u * f / 100.0;
			if(dis < 0)
			{
				flag = false;
				break;
			}
		}
		if(flag)
			printf("success");
		else
			printf("failure");
		printf(" on day %d\n", day);
	}
	return 0;
}