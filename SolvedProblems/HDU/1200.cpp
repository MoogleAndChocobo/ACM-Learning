#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cctype>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof(a))
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define sfs(a) scanf("%s", a)
#define pb(a) push_back(a)

const int MAX = 1e3 + 5;
const int N = 1e3;
const int INF = 0x3f3f3f3f;

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
#endif

	int n;
	while(~sfi(n) && n)
	{
		char s[MAX];
		char ans[MAX][MAX];
		sfs(s);
		int len = strlen(s);
		int dir = 1;
		rep(i, 0, len - 1)
		{
			int row = (i + 1) / n;
			if((i + 1) % n)
				row++;
			if(dir)
			{
				int tmp = (i + 1) % n;
				if(tmp == 0)
					tmp = n;
				ans[row][tmp] = s[i];
			}
			else
			{
				int tmp = (i + 1) % n;
				if(!tmp)
					tmp = n;
				ans[row][n + 1 - tmp] = s[i];
			}
			if((i + 1) % n == 0)
				dir = !dir;
		}
		int m = len / n;
		if(len % n)
			m++;
		int cnt = 0;
		//~ rep(i, 1, n)
		//~ {
			//~ rep(j, 1, m)
			//~ {
				//~ if(isalpha(ans[j][i]))
					//~ putchar(ans[j][i]);
				//~ else
					//~ putchar(' ');
				//~ putchar(' ');
			//~ }
			//~ putchar('\n');
		//~ }
		rep(i, 1, n)
		{
			rep(j, 1, m)
			{
				if(ans[j][i])
				{
					cnt++;
					putchar(ans[j][i]);
				}
				if(cnt == len)
					break;
			}
		}
		putchar('\n');
	}
	return 0;
}