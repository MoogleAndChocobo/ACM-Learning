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

char s[MAX][MAX];

int main()
{
	int T;
	sfi(T);
	rep(kase, 1, T)
	{
		mem(s);
		int n;
		sfi(n);
		rep(i, 1, n)
			s[i][i] = 'X';
		rep(i, 1, n)
			s[i][n - i + 1] = 'X';
		rep(i, 1, n)
		{
			rep(j, 1, n)
			{
				if(i <= n / 2 && j > n - i + 1)
					break;
				if(i == n / 2 + 1 && j > n / 2 + 1)
					break;
				if(i > n / 2 + 1 && j >= i + 1)
					break;
				if(s[i][j] != 'X')
					putchar(' ');
				else
					putchar('X');
			}
			putchar('\n');
		}
		putchar('\n');
	}
	return 0;
}