#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%lld", a)

const int MAX = 3e5 + 5;

int main()
{

	int T;
	sfi(T);
	while(T--)
	{
		double a, b, c;
		scanf("%lf%lf%lf", &a, &b, &c);
		if(!a)
		{
			if(!b && !c)
				puts("INF");
			else if(!b && c)
				puts("0");
			else
				puts("1");
		}
		else
		{
			double now = b * b - 4 * a * c;
			if(now == 0)
				puts("1");
			else if(now > 0)
				puts("2");
			else
				puts("0");
		}
	}
	return 0;
}