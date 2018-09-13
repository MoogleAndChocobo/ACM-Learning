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

const int MAX = 1e5 + 10;
const int N = 65536;
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1007;
const double EPS = (double)1e-10;
const int LMON[15] = {31,29,31,30,31,30,31,31,30,31,30,31};
const int CMON[15] = {31,29,31,30,31,30,31,31,30,31,30,31};
const int diro[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
const int dirt[6][3] = {{0,0,1},{0,0,-1},{1,0,0},{-1,0,0},{0,1,0},{0,-1,0}};

struct Student1
{
	string order, name;
	int score;
	Student1(string oo = "", string nn = "", int ss = 0):order(oo), name(nn), score(ss){}
	friend bool operator <(Student1 a, Student1 b)
	{
		return a.order < b.order;
	}
};

struct Student2
{
	string order, name;
	int score;
	Student2(string oo = "", string nn = "", int ss = 0):order(oo), name(nn), score(ss){}
	friend bool operator <(Student2 a, Student2 b)
	{
		if(a.name != b.name)
			return a.name < b.name;
		else
			return a.order < b.order;
	}
};

struct Student3
{
	string order, name;
	int score;
	Student3(string oo = "", string nn = "", int ss = 0):order(oo), name(nn), score(ss){}
	friend bool operator <(Student3 a, Student3 b)
	{
		if(a.score != b.score)
			return a.score < b.score;
		else
			return a.order < b.order;
	}
};

int main()
{
#ifdef LOCAL
	//~ fli
	//~ flo
#endif	//LOCAL

	sync

	int n, opr;
	int cnt = 0;
	while(cin >> n >> opr)
	{
		if(!n && !opr)
			break;
		cout << "Case " << ++cnt << ":" << endl;
		if(opr == 1)
		{
			Student1 s1[MAX];
			rep(i, 1, n)
				cin >> s1[i].order >> s1[i].name >> s1[i].score;
			sort(s1 + 1, s1 + 1 + n);
			rep(i, 1, n)
			{
				cout << s1[i].order << " " << s1[i].name << " " << s1[i].score << endl;
			}
		}
		else if(opr == 2)
		{
			Student2 s2[MAX];
			rep(i, 1, n)
				cin >> s2[i].order >> s2[i].name >> s2[i].score;
			sort(s2 + 1, s2 + 1 + n);
			rep(i, 1, n)
			{
				cout << s2[i].order << " " << s2[i].name << " " << s2[i].score << endl;
			}
		}
		else if(opr == 3)
		{
			Student3 s3[MAX];
			rep(i, 1, n)
				cin >> s3[i].order >> s3[i].name >> s3[i].score;
			sort(s3 + 1, s3 + 1 + n);
			rep(i, 1, n)
			{
				cout << s3[i].order << " " << s3[i].name << " " << s3[i].score << endl;
			}
		}
	}
	return 0;
}