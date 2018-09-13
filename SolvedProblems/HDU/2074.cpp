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

const int MAX = 1e2 + 5;

int main()
{
	int n;
	char a[MAX], b[MAX];
	bool f = false;
	while(~scanf("%d%s%s", &n, a, b))
	{
		if(f)
			putchar('\n');
		if(n == 1)
		{
			printf("%c\n", a[0]);
			f = true;
			continue;
		}
		char ca = a[0], cb = b[0];
		if(n / 2 % 2 == 1)
			swap(ca, cb);
		char s[MAX][MAX];
		s[1][1] = s[1][n] = s[n][1] = s[n][n] = ' ';
		rep(i, 2, n - 1)
			s[1][i] = s[i][1] = s[n][i] = s[i][n] = ca;
		int lmt = n / 2 + 1;
		rep(i, 2, lmt)
		{
			char tmp;
			tmp = i % 2 ? ca : cb;
			s[i][i] = s[i][n - i + 1] = s[n - i + 1][i] = s[n - i + 1][n - i + 1] = tmp;
			rep(j, i, n - i + 1)
				s[i][j] = s[j][i] = s[n - i + 1][j] = s[j][n - i + 1] = tmp;
		}
		rep(i, 1, n)
		{
			rep(j, 1, n)
				putchar(s[i][j]);
			putchar('\n');
		}
		f = true;
	}
	return 0;
}