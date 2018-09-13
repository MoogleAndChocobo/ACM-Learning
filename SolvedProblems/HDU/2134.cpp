#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%lld", a)
#define sfd(a) scanf("%lf", &a)

const double PI = acos(-1.);
const int MAX = 1e4 + 5;
const int N = 1e7;
const double eps = 1e-8;


int main()
{

	int R;
	while(~sfi(R) && R)
	{
		double r1 = sqrt((double)R * (double)R / 3.);
		double r2 = r1 * sqrt(2.);
		printf("%.3lf %.3lf\n", r1, r2);
	}
	return 0;
}