#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e2 + 10;

#define rep(i, a, b) for(int i = a; i <= b; i++)

int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		int s[MAX] = {0};
		rep(i, 1, n)
		{
			scanf("%d", &s[i]);
		}
		sort(s + 1, s + n + 1);
		set<int> ans;
		rep(i, 1, n)
		{
			if(!s[i])
				continue;
			int cnt = 0;
			rep(j, 1, n)
			{
				if(s[j] >= s[i])
					cnt++;
			}
			ans.insert(cnt);
		}
		printf("%d\n", (int)ans.size());
	}
	return 0;
}