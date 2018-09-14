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

const int MAX = 1e3 + 5;
const int N = 1e3;

int n, m;


char pic[MAX][MAX];
int rec[MAX][MAX];

void modify(int x, int y, int num)
{
	rep(i, 1, x)
		rep(j, 1, y)
			rec[i][j] += num;
}

void print()
{
	rep(i, 1, n)
	{
		rep(j, 1, m)
		{
			cout << rec[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	rep(i, 1, n)
	{
		rep(j, 1, m)
		{
			cin >> pic[i][j];
		}
	}
	
	int ans = 0;
	dow(i, n, 1)
	{
		dow(j, m, 1)
		{
			if(pic[i][j] == 'B' && rec[i][j] != -1)
			{
				ans++;
				modify(i, j, -1 - rec[i][j]);
				//~ print();
			}
			else if(pic[i][j] == 'W' && rec[i][j] != 1)
			{
				ans++;
				modify(i, j, 1 - rec[i][j]);
				//~ print();
			}
		}
	}
	cout << ans << endl;
	return 0;
}