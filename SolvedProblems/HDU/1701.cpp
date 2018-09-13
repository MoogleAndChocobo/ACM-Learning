#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%lld", a)

const int MAX = 1e5 + 5;


int main()
{
	int T;
	sfi(T);
	while(T--)
	{
		double a, b;
		scanf("%lf%lf", &a, &b);
		int ans = 1;
		while((int)((double)ans * a / 100.0) >= (int)((double)ans * b / 100.0)) ans++;
		printf("%d\n", ans);
	}
	return 0;
}