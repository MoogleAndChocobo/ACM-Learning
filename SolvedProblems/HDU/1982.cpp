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
	getchar();
	rep(kase, 1, T)
	{
		char s[MAX];
		fgets(s, 10002, stdin);
		int len = strlen(s);
		if(s[len - 1] != '\n')
			s[len++] = '\n';
		int num = 0;
		bool f = false;
		rep(i, 0, len - 1)
		{
			if(isdigit(s[i]))
			{
				num = num * 10 + s[i] - '0';
				f = true;
			}
			else if(s[i] == '\n')
			{
				if(f)
					putchar(num + 'A' - 1);
				break;
			}
			else if(s[i] == '#')
			{
				if(f)
					putchar(num + 'A' - 1);
				putchar(' ');
				f = false, num = 0;
			}
			else
			{
				if(f)
					putchar(num + 'A' - 1);
				f = false, num = 0;
			}
		}
		putchar('\n');
	}
	return 0;
}