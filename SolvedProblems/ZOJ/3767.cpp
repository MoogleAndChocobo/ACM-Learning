#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int sum, n, m, k;
		scanf("%d%d", &n, &m);
		sum = 0;
		while (n--)
		{
			scanf("%d", &k);
			sum += k;
		}
		if (sum > m)
			printf("Warning\n");
		else
			printf("Safe\n");
	}
	return 0;
}