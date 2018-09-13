#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define sfi(a) scanf("%d", &a)
#define rep(i, a, b) for(int i = a; i <= b; i++)
int main()
{
	int n;
	while(~sfi(n) && n)
	{
		int a = 0;
		rep(i, 1, 65)
		{
			if((18 + i * n) % 65)
				continue;
			else
			{
				a = i;
				break;
			}
		}
		if(a)
			printf("%d\n", a);
		else
			puts("no");
	}
	return 0;
}