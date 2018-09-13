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

	double h, l, v;
	while(~scanf("%lf%lf%lf", &h, &l, &v))
	{
		if(h == 0 && l == 0 && v == 0)
			break;
		printf("%.2lf\n", v * v / ( 2 * 9.8) - 0.5 * 9.8 * l * l / (v * v) + h);
	}
	return 0;
}