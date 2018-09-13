#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cctype>
#include <queue>
#include <set>
#include <map>
#include <iostream>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LF;

#define fli				freopen("in.txt", "r", stdin);
#define flo				freopen("out.txt", "w", stdout);
#define sync 			ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define	rep(i, a, b)	for(int i = a; i <= b; i++)
#define dow(i, a, b)	for(int i = a; i >= b; i--)
#define mem(a)			memset(a, 0, sizeof(a))
#define mst(a, b)		memset(a, b, sizeof(a))
#define sfi(a)			scanf("%d", &a)
#define sfs(a)			scanf("%s", a)
#define sfl(a)			scanf("%lld", &a)
#define sfd(a)			scanf("%lf", &a)
#define pb(a)			push_back(a)
#define all(c)			(c).begin(),(c).end()
#define YES				puts("YES")
#define NO				puts("NO")
#define yes				puts("yes")
#define no				puts("no")
#define Yes				puts("Yes")
#define No				pus("No")

const int MAX = 1e3 + 10;
const int N = 205;
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1007;
const double EPS = (double)1e-10;
const int LMON[15] = {31,29,31,30,31,30,31,31,30,31,30,31};
const int CMON[15] = {31,29,31,30,31,30,31,31,30,31,30,31};
const int diro[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
const int dirt[6][3] = {{0,0,1},{0,0,-1},{1,0,0},{-1,0,0},{0,1,0},{0,-1,0}};

struct Node
{
	string name, time;
	int rk;
	Node(string nn = "", string tt = ""):name(nn), time(tt){}
	friend bool operator <(Node a, Node b)
	{
		if(a.time != b.time)
			return a.time < b.time;
		else
			return a.name < b.name;
	}
	friend bool operator ==(Node a, Node b)
	{
		return a.time == b.time;
	}
};

int main()
{
#ifdef LOCAL
	//~ fli
	//~ flo
#endif	//LOCAL

	int kase = 0;
	int n;
	bool f = false;
	while(cin >> n && n)
	{
		if(f)
			putchar('\n');
		Node s[MAX];
		rep(i, 1, n)
			cin >> s[i].name >> s[i].time;
		cout << "Case #" << ++kase << endl;
		sort(s + 1, s + n + 1);
		int rk = 0;
		rep(i, 1, n)
		{
			if(!(s[i] == s[i - 1]))
				rk = i;
			cout << s[i].name << " " << rk << endl;
		}
		f = true;
	}
	return 0;
}