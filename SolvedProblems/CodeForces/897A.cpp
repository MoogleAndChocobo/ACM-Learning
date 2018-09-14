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

const int MAX = 1e3 + 5;
const int N = 1e5;

int main()
{
	int n, opr;
	char s[MAX];
	scanf("%d%d%s", &n, &opr, s);
	while(opr--)
	{
		int l, r;
		char st, en;
		scanf("%d %d %c %c", &l, &r, &st, &en);
		rep(i, l - 1, r - 1)
		{
			if(s[i] == st)
				s[i] = en;
		}
	}
	rep(i, 0, n - 1)
		putchar(s[i]);
	putchar('\n');
	return 0;
}