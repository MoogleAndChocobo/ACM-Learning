#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cctype>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define sfs(a) scanf("%s", a)

const int MAX = 1e5 + 5;
const int N = 1e3;

int main()
{
	int n;
	while(~sfi(n))
	{
		if(n % 4 == 0)
		{
			puts("0");
			printf("%d", n / 2);
			for(int i = 1; i <= n / 2; i += 2)
				printf(" %d %d", i, n - i + 1);
		}
		else if(n % 4 == 1)
		{
			puts("1");
			printf("%d", n / 2);
			for(int i = 2; i <= n / 2; i += 2)
				printf(" %d %d", i, n - i + 2);
		}
		else if(n % 4 == 2)
		{
			puts("1");
			printf("%d", n / 2);
			for(int i = 1; i <= n / 2 - 1; i += 2)
				printf(" %d %d", i, n - i + 1);
			printf(" %d", n / 2);
		}
		else
		{
			puts("0");
			printf("%d", n / 2 + 1);
			for(int i = 2; i <= n / 2; i += 2)
				printf(" %d %d", i, n - i + 2);
			printf(" %d %d", 1, n / 2 + 1); 
		}
		putchar('\n');
	}
	
	return 0;
}