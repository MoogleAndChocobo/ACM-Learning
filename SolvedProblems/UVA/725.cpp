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

bool judge(int x)
{
	return x >= 1234 && x <= 98765;
}

bool check(int x, int y)
{
	if(!judge(x) || !judge(y))
		return false;
	bool vis[15] = {0};
	if(x < 10000 || y < 10000)
		vis[0] = true;
	while(x)
	{
		vis[x % 10] = true;
		x /= 10;
	}
	while(y)
	{
		vis[y % 10] = true;
		y /= 10;
	}
	rep(i, 0, 9)
	{
		if(!vis[i])
			return false;
	}
	return true;
}

int main()
{
	int n;
	bool checkblank = false;
	while(~sfi(n) && n)
	{
		if(checkblank)
			putchar('\n');
			
		bool is = false;
		int x = 1234;
		rep(i, x, 98765)
		{
			int now = i * n;
			if(check(i, now))
			{
				printf("%05d / %05d = %d\n", now, i, n);
				is = true;
			}
		}
		
		if(!is)
			printf("There are no solutions for %d.\n", n);
		
		checkblank = true;
	}
	return 0;
}