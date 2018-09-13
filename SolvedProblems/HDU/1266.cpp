//~ #define LOCAL

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<iostream>
#include<cmath>
#include<cctype>
#include<vector>
#include<set>
#include<queue>

using namespace std;

typedef long long LL;

const int MAX = 1e3 + 10;
const int N = 1e3;
const int INF = 0x3f3f3f3f;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
#endif	//LOCAL

	int T;
	sfi(T);
	rep(i, 1, T)
	{
		char s[MAX];
		sfs(s);
		bool flag = s[0] == '-';
		int len = strlen(s);
		if(flag)
		{
			len--;
			rep(i, 0, len - 1)
			{
				s[i] = s[i + 1];
			}
		}
		int cnt = 0;
		dow(i, len - 1, 0)
		{
			if(s[i] == '0')
			{
				cnt++;
			}
			else
				break;
		}
		if(flag)
			putchar('-');
		dow(i, len - cnt - 1, 0)
			putchar(s[i]);
		rep(i, 1, cnt)
			putchar('0');
		putchar('\n');
	}

	return 0;
}