//~ #define LOCAL

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <list>
#include <cctype>
#include <ctime>
#include <functional>
#include <cmath>

using namespace std;

typedef unsigned U;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> pii;

const int MAX = 1e6 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const LL LINF = 0x3f3f3f3f3f3f3f;

#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfc(a) scanf("%c", &c)
#define sfs(a) scanf("%s", a)
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))

bool rec[MAX];

int main()
{
	
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	//ios::sync_with_stdio(false);
	//cin.tie(0);

	rep(i, 1, 1e6)
	{
		string tmp;
		int now = i;
		while(now)
		{
			tmp += (now % 10) + '0';
			now /= 10;
		}
		reverse(tmp.begin(), tmp.end());
		if(tmp.find("4") == -1 && tmp.find("62") == -1)
		{
			rec[i] = true;
		}
	}

	int mn, mx;
	while(~scanf("%d%d", &mn, &mx) && !(!mn && !mx))
	{
		int cnt = 0;
		rep(i, mn, mx)
		{
			if(rec[i])
				cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}