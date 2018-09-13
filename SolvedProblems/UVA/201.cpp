#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define mem(a) memset(a, 0, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define sfs(a) scanf("%s", a)

const int MAX = 20 + 5;
const int N = 1e3;

struct Point
{
	bool d, r;
	Point(bool dd = false, bool rr = false):d(dd), r(rr){}
};

int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int kase = 0;
	bool checkblank = false;
	int n, times;
	while(~scanf("%d%d", &n, &times))
	{
		if(checkblank)
			puts("\n**********************************\n");
		
		Point pic[MAX][MAX];
		while(times--)
		{
			char opr[MAX];
			int i, j;
			scanf("%s%d%d", opr, &i, &j);
			if(opr[0] == 'H')
				pic[i][j].r = true;
			else
				pic[j][i].d = true;
		}
		
		int ans[MAX] = {0};
		
		rep(p, 1, n - 1)
		{
			rep(q, 1, n - 1)
			{
				int mxc = min(n - q, n - p);
				rep(c, 1, mxc)
				{
					rep(j, p, p + c - 1)
						if(!pic[q][j].r || !pic[q + c][j].r)
							goto N;
					rep(j, q, q + c - 1)
						if(!pic[j][p].d || !pic[j][p + c].d)
							goto N;
					ans[c]++;
					N:;
				}
			}
		}
		
		bool flag = false;
		printf("Problem #%d\n\n", ++kase);
		rep(i, 1, n)
		{
			int len = ans[i];
			if(ans[i])
				printf("%d square (s) of size %d\n", len, i), flag = true;;
		}
		if(!flag)
			puts("No completed squares can be found.");
		checkblank = true;
	}
	return 0;
}