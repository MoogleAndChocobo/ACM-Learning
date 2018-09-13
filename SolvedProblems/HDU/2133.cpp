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
const int N = 205;
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1007;
const double EPS = (double)1e-10;
const int LMON[15] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
const int CMON[15] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
const int diro[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
const int dirt[6][3] = {{0,0,1},{0,0,-1},{1,0,0},{-1,0,0},{0,1,0},{0,-1,0}};

int main()
{
#ifdef LOCAL
	//~ fli
	//~ flo
#endif	//LOCAL

	sync
	
	int y, m, d;
	while(cin >> y >> m >> d)
	{
		bool isleap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
		if(y == 0 || m == 0 || d == 0 || (isleap && LMON[m] < d) || (!isleap && CMON[m] < d))
		{
			cout << "illegal" << endl;
			continue;
		}
		int sum = d;
		rep(i, 1, y - 1)
		{
			if((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
				sum += 366;
			else
				sum += 365;
		}
		rep(i, 1, m - 1)
		{
			if(isleap)
				sum += LMON[i];
			else
				sum += CMON[i];
		}
		sum %= 7;
		string ans = "";
		switch(sum)
		{
			case 0: ans = "Sunday";break;
			case 1: ans = "Monday";break;
			case 2: ans = "Tuesday";break;
			case 3: ans = "Wednesday";break;
			case 4: ans = "Thursday";break;
			case 5: ans = "Friday";break;
			case 6: ans = "Saturday";break;
		}
		cout << ans << endl;
	}
	return 0;
}