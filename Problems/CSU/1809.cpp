#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i <= b; i++)
#define sfi(a) scanf("%d", &a)
#define mem(a) memset(a, 0, sizeof(a))

const int MAX = 1e5 + 5;

char s[MAX];
int ra[MAX], rb[MAX], rec[MAX];

int main()
{
	int n, m;
	while(~scanf("%d%d", &n, &m))
	{
		scanf("%s", s);
		mem(ra), mem(rb);
		int len = strlen(s);
		int ca = 0, cb = 0;
		rep(i, 0, len - 1)
		{
			if(s[i] == '(')
				ca++;
			else
				cb++;
			ra[i + 1] = ca;
			rb[i + 1] = cb;
			rec[i + 1] = rec[i];
			if(ca - cb <= 1)
				rec[i + 1]++;
		}
		rep(i, 1, m)
		{
			int tmpx, tmpy;
			scanf("%d%d", &tmpx, &tmpy);
			if(s[tmpx - 1] == s[tmpy - 1])
			{
				puts("Yes");
				continue;
			}
			if(tmpx == 1 || tmpy == 1 || tmpx == len || tmpy == len)
			{
				puts("No");
				continue;
			}
			int x = min(tmpx, tmpy);
			int y = max(tmpx, tmpy);
			if(s[x - 1] == ')')
				puts("Yes");
			else
			{
				if(rec[y - 1] - rec[x - 1] != 0)
					puts("No");
				else
					puts("Yes");
			}
		}
	}
	return 0;
}