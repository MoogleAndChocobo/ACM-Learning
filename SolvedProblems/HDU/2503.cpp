#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof(a))
#define sfi(a) scanf("%d", &a)

int gcd(int a, int b)
{
	if(a < b)
		swap(a, b);
	while(b)
	{
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

int main()
{
	int T;
	sfi(T);
	rep(kase, 1, T)
	{
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		int q = b * d;
		int p = a * d + b * c;
		int tmp = gcd(p, q);
		printf("%d %d\n", p / tmp, q / tmp);
	}
	return 0;
}