#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, n;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		int ans = 0;
		while (n--)
		{
			int k;
			scanf("%d", &k);
			if (k > 6000)
				++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}