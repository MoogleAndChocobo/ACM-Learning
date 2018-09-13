#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

typedef long long LL;
typedef long long ll;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define mem(a) memset(a, 0, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define sync ios::sync_with_stdio(0); cin.tie(0);

const int MAX = 1e3 + 5;

int main()
{
	int T;
	sfi(T);
	rep(kase, 1, T)
	{
		char s[MAX];
		int n;
		scanf("%s%d", s, &n);
		char c = s[0];


		int tmp = n / 6 + 1;
		int ttmp = (n - 3) / 2;
		int x = n - 3 - ttmp;

		rep(i, 1, tmp)
			putchar(' ');
		rep(i, 1, x)
			putchar(c);
		//~ rep(i, 1, tmp)
			//~ putchar(' ');
		putchar('\n');
		rep(i, 1, ttmp)
		{
			rep(j, 1, tmp)
				putchar(c);
			rep(j, 1, x)
				putchar(' ');
			rep(j, 1, tmp)
				putchar(c);
			putchar('\n');
		}
		rep(i, 1, tmp)
			putchar(' ');
		rep(i, 1, x)
			putchar(c);
		//~ rep(i, 1, tmp)
			//~ putchar(' ');
		putchar('\n');
		rep(i, 1, x)
		{
			rep(j, 1, tmp)
				putchar(c);
			rep(j, 1, x)
				putchar(' ');
			rep(j, 1, tmp)
				putchar(c);
			putchar('\n');
		}
		rep(i, 1, tmp)
			putchar(' ');
		rep(i, 1, x)
			putchar(c);
		//~ rep(i, 1, tmp)
			//~ putchar(' ');
		putchar('\n');

		if(kase != T)
			putchar('\n');
	}
	return 0;
}