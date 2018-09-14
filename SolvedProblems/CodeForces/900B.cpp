#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define sfs(a) scanf("%s", a)
#define mem(a) memset(a, 0, sizeof(a))

const int MAX = 1e5 + 5;
const int N = 1e5;

int main()
{
	int a, b, num;
	scanf("%d%d%d", &a, &b, &num);
	a %= b;
	rep(i, 1, 10000)
	{
		a *= 10;
		int tmp = a / b;
		a %= b;
		if(tmp == num)
		{
			printf("%d\n", i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}