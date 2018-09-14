#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof(a))

const int MAX = 1e3 + 10;

bool org[MAX] = {0};
int loc[MAX] = {0};

bool check(int n)
{
	rep(i, 1, n)
	{
		if(!org[i])
			return false;
	}
	return true;
}

int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		mem(org), mem(loc);
		
		int n, k;
		scanf("%d%d", &n, &k);
		int cnt = 1;
		rep(i, 1, k)
		{
			int tmp;
			scanf("%d", &tmp);
			org[tmp] = true;
			loc[i] = tmp;
		}
		while(!check(n))
		{
			rep(i, 1, k)
			{
				if(loc[i] - cnt >= 1)
					org[loc[i] - cnt] = true;
				if(loc[i] + cnt <= n)
					org[loc[i] + cnt] = true;
			}
			cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}