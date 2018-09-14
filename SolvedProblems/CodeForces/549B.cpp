#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define sfs(a) scanf("%s", a)
#define mem(a) memset(a, 0, sizeof(a))
#define all(a) a.begin(), a.end()

const int MAX = 1e3 + 5;
const int N = 1e3;
const double eps = 1e-10;

int rec[MAX][MAX];
int gt[MAX];
int guess[MAX];
vector<int> ans;

int main()
{
	int n;
	sfi(n);
	rep(i, 1, n)
		rep(j, 1, n)
			scanf("%1d", &rec[i][j]);
	rep(i, 1, n)
		sfi(guess[i]);
		
	rep(times, 1, n)
	{
		rep(i, 1, n)
		{
			if(guess[i] == 0)
			{
				rep(j, 1, n)
					if(rec[i][j])
						guess[j]--;
				ans.push_back(i);
			}
		}
	}
	int len = ans.size();
	printf("%d\n", len);
	rep(i, 0, len - 1)
	{
		printf("%d", ans[i]);
		putchar(i != len - 1 ? ' ' : '\n');
	}
	return 0;
}