//~ #define LOCAL

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<iostream>
#include<vector>
#include<sstream>
#include<map>
#include<set>
#include<cmath>
#include<cctype>
#include<functional>
#include<ctime>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LF;

const int dirnd[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
const int dirrd[6][3] = {{0,0,1},{0,0,-1},{1,0,0},{-1,0,0},{0,1,0},{0,-1,0}};
const int MAX = 1e4 + 5;
const int N = 1e4;
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f;

#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfu(a) scanf("%llu", &a)
#define sfd(a) scanf("%ld", &a)
#define sfs(a) scanf("%s", a)
#define sfc(a) getchar(a)
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))

const char dirName[10][10] = {"L", "Turning", "R"};

int order[MAX];

struct Ant
{
	int dis, id, turn;
	Ant(int dd = 0, int ii = 0, int tt = 0):dis(dd), id(ii), turn(tt){}
	friend bool operator <(Ant a, Ant b)
	{
		return a.dis < b.dis;
	}
} before[MAX], after[MAX];

int main()
{
	
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL


	int T;
	sfi(T);
	rep(kase, 1, T)
	{
		int l, endtime, n;
		scanf("%d%d%d", &l, &endtime, &n);
		rep(i, 1, n)
		{
			int dis;
			char c;
			scanf("%d %c", &dis, &c);
			int turn = (c == 'L') ? -1 : 1;
			before[i] = Ant(dis, i, turn);
			after[i] = Ant(dis + endtime * turn, 0, turn);
		}

		sort(before + 1, before + 1 + n);
		rep(i, 1, n)
		{
			order[before[i].id] = i;
		}

		sort(after + 1, after + 1 + n);
		rep(i, 1, n - 1)
		{
			if(after[i].dis == after[i + 1].dis)
				after[i].turn = after[i + 1].turn = 0;
		}

		printf("Case #%d:\n", kase);
		rep(i, 1, n)
		{
			int idx = order[i];
			if(after[idx].dis < 0 || after[idx].dis > l)
				printf("Fell off\n");
			else
				printf("%d %s\n", after[idx].dis, dirName[after[idx].turn + 1]);
		}
		putchar('\n');
	}
	return 0;
}