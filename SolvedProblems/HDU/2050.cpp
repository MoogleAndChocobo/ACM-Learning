#include <stdio.h>

int main()
{
	int m, n;
	int a[100000];
	for (int i = 1; i < 100000; i++)
		a[i] = 2 * i * i - i + 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &m);
		printf("%d\n", a[m]);
	}
}