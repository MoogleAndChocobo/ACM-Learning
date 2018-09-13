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

const int MAX = 1e4 + 10;
const int N = 2e4;

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
#define yes puts("yes")
#define no puts("no");
#define Yes puts("Yes")
#define No puts("No")
#define YES puts("YES")
#define NO puts("NO")

struct Node
{
	int num, cost;
	double per;
	Node(int nn = 0, int cc = 0, double pp = 0.0):num(nn), cost(cc), per(pp){}
	friend bool operator <(Node a, Node b)
	{
		return a.per > b.per;
	}
};

int main()
{
#ifdef LOCAL
	//~ fli
	//~ flo
#endif	//LOCAL

	int m, n;
	while(~scanf("%d%d", &m, &n))
	{
		if(!(n + 1) && !(m + 1))
			break;
		Node s[MAX];
		rep(i, 1, n)
		{
			scanf("%d%d", &s[i].num, &s[i].cost);
			s[i].per = (double)s[i].num / (double)s[i].cost;
		}
		sort(s + 1, s + n + 1);
		double ans = 0;
		rep(i, 1, n)
		{
			if(s[i].cost < m)
			{
				ans += s[i].num;
				m -= s[i].cost;
			}
			else
			{
				ans += m / (double)s[i].cost * (double)s[i].num;
				m = 0;
				break;
			}
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}