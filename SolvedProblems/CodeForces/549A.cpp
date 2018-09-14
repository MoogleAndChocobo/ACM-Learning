#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define sfs(a) scanf("%s", a)
#define mem(a) memset(a, 0, sizeof(a))

const int MAX = 1e3 + 5;
const int N = 1e3;


char pic[MAX][MAX];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	rep(i, 1, n)
	{
		rep(j, 1, m)
		{
			cin >> pic[i][j];
		}
	}
	if(n < 1 || m < 1)
	{
		puts("0");
		return 0;
	}
	int ans = 0;
	rep(i, 1, n - 1)
	{
		rep(j, 1, m - 1)
		{
			int a = 0, b = 0, c = 0, d = 0;
			if(pic[i][j] == 'f' || pic[i + 1][j] == 'f' || pic[i + 1][j + 1] == 'f' || pic[i][j + 1] == 'f')
				a++;
			if(pic[i][j] == 'a' || pic[i + 1][j] == 'a' || pic[i + 1][j + 1] == 'a' || pic[i][j + 1] == 'a')
				b++;
			if(pic[i][j] == 'c' || pic[i + 1][j] == 'c' || pic[i + 1][j + 1] == 'c' || pic[i][j + 1] == 'c')
				c++;
			if(pic[i][j] == 'e' || pic[i + 1][j] == 'e' || pic[i + 1][j + 1] == 'e' || pic[i][j + 1] == 'e')
				d++;
			if(a == 1 && b == 1 && c == 1 && d == 1)
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}