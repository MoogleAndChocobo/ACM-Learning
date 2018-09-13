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

const int MAX = 1e4 + 5;

int main()
{
	int T;
	sfi(T);
	rep(kase, 1, T)
	{
		int n;
		char s[MAX];
		scanf("%d%s", &n, s);
		printf("%d ", kase);
		int len = strlen(s);
		rep(i, 0, len - 1)
		{
			if(i + 1 != n)
				putchar(s[i]);
		}
		putchar('\n');
	}
	return 0;
}