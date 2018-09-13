#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define mem(a) memset(a, 0, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define sfs(a) scanf("%s", a)

const int MAX = 1e3 + 5;
const int N = 1e3;

int main()
{
	int n;
	int kase = 0;
	while(~sfi(n))
	{
		LL s[MAX] = {0};
		rep(i, 1, n)
			sfl(s[i]);
		LL mx = 0;
		rep(i, 1, n)
		{
			LL pro = 1;
			rep(j, i, n)
			{
				pro *= s[j];
				mx = max(mx, pro);
			}
		}
		printf("Case #%d: The maximum product is ", ++kase);
		if(mx >= 0)
			printf("%lld", mx);
		else
			putchar('0');
		puts(".\n");
	}
	return 0;
}