#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i <= b; i++)

const int MAX = 1e5 + 10;

typedef long long LL;

char s[MAX];

int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		scanf("%s", s);
		int len = strlen(s);
		int x = 0, y = 0, ans = 0;
		bool origin = false;
		rep(i, 0, len - 1)
		{
			bool pre = origin;
			if(s[i] == 'U')
				x++;
			else if(s[i] == 'R')
				y++;
			if(x > y)
				origin = true;
			else if(x < y)
				origin = false;
			if(!i)
				continue;
			if(pre != origin)
			{
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}