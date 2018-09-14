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
	int n;
	sfi(n);
	int ca = 0, cb = 0;
	rep(i, 1, n)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if(x > 0)
			ca++;
		else
			cb++;
	}
	if(ca == 1 || cb == 1 || !ca || !cb)
		puts("Yes");
	else
		puts("No");
	return 0;
}