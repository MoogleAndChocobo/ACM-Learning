#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <cmath>
#include <cctype>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;

#define rep(i, a, b) for(int i = a; i <=b; i++)
#define dow(i, a, b) for(int i = a; i >=b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf"£¬ &a)
#define sfs(a) scanf("%s", a)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(a) a.begin(),a.end()
#define fli freopen("in.txt", "r", stdin);
#define flo freopen("out.txt", "w",stdout);
#define pb(a) push_back(a)
#define yes puts("yes");
#define no puts("no");
#define Yes puts("Yes");
#define No puts("No");
#define YES puts("YES");
#define NO puts("NO");

const int dirnd[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
const int dirrd[6][3] = {{0,1,0},{0,-1,0},{-1,0,0},{1,0,0},{0,0,1},{0,0,-1}};
const int MOD = 1e9 + 9;
const int MAX = 1e3 + 10;
const int INF = 0x3f3f3f3f;
const int N = 1e3;
const LL LINF = 0x3f3f3f3f3f3f3f;

int rec[MAX];

void init(void)
{
	rep(i, 1, 5000)
	{
		int cnt = 0;
		rep(j, 1, i)
		{
			if(i % j == 0)
				cnt++;
		}
		rec[i] = cnt;
	}
}

int main()
{
#ifdef LOCAL
	//~ fli
	//~ flo
#endif	//LOCAL

	int T;
	sfi(T);
	rep(i, 1, T)
	{
		int n, k;
		sfi(n);
		sfi(k);
		int s[MAX] = {0};
		rep(i, 1, n)
		{
			sfi(s[i]);
		}
		bool vis[2010] = {0};
		vector<int> c;
		rep(i, 1, n)
		{
			rep(j, 1, n)
			{
				if(i != j)
				{
					int now = (s[i] > s[j]) ? s[i] - s[j] : s[j] - s[i];
					if(!vis[now])
					{
						c.pb(now);
						vis[now] = true;
					}
				}
			}
		}
		sort(all(c));
		printf("%d\n", c[k - 1]);
	}
	return 0;
}