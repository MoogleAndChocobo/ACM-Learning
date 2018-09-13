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

const int MAX = 1e3 + 10;

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
	int a, b;
	Node(int aa = 0, int bb = 0):a(aa), b(bb){}
	friend bool operator <(Node m, Node n)
	{
		return m.a < n.a;
	}
};

int main()
{
#ifdef LOCAL
	//~ fli
	//~ flo
#endif	//LOCAL

	int T;
	sfi(T);
	rep(kase, 1, T)
	{
		Node s[MAX];

		int n;
		sfi(n);
		rep(i, 1, n)
		{
			scanf("%d%d", &s[i].a, &s[i].b);
		}
		sort(s + 1, s + n + 1);
		rep(i, 1, n)
		{
			rep(j, 1, s[i].b)
			{
				printf(">+");
				rep(k, 1, s[i].a - 2)
					putchar('-');
				puts("+>");
			}
			putchar('\n');
		}
	}
	return 0;
}