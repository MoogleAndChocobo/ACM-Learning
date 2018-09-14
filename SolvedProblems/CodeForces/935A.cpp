#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i <= b; i++)

const int MAX = 1e5 + 10;

typedef long long LL;

int s[MAX];

int main()
{
	rep(i, 1, MAX - 10)
	{
		for(int j = i + i; j <= MAX - 10; j += i)
		{
			s[j]++;
		}
	}
	int n;
	while(~scanf("%d", &n))
		printf("%d\n", s[n]);
	return 0;
}