#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i <= b; i++)

const int MAX = 2 * 1e5 + 10;

int s[MAX];
char vis[MAX];

int main()
{
	int n;
	scanf("%d", &n);
	rep(i, 0, n - 1)
		scanf("%d", &s[i]);
	scanf("%s", vis);
	rep(i, 0, n - 2)
	{
		if(vis[i] == '0')
		{
			if(i != 0 && s[i] < s[i - 1])
			{
				printf("NO\n");
				return 0;
			}
		}
		else if(vis[i] == '1')
		{
			for(int j = i; j <= n - 2; j++)
			{
				if(vis[j] == '0' || j == n - 2)
				{
					if(vis[j] == '0')
						sort(s + i, s + j + 1);
					else if(j == n - 2)
						sort(s + i, s + j + 2);
					if(i != 0 && s[i] < s[i - 1])
					{
						printf("NO\n");
						return 0;
					}
					i = j;
					break;
				}
			}
		}
	}
	if(s[n - 1] < s[n - 2])
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	return 0;
}