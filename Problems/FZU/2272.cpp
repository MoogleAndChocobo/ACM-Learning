#include<cstdio>
int main()
{
	int t;
	int n, m;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		int y = (m - 2 * n) / 2;
		int x = n - y;
		printf("%d %d\n", y, x);
	}
	return 0;
}