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

const int MAX = 1e5 + 10;
const int N = 1e3;
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f;

#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%ld", &a)
#define sfs(a) scanf("%s", a)
#define sfc(a) getchar(a)
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))

int main()
{
	
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	int test;
	sfi(test);
	rep(i, 1, test)
	{
		int n;
		sfi(n);
		int s[MAX] = {0};
		rep(j, 1, n)
		{
			sfi(s[j]);
		}
		int ans, tmpsum, st, en, tmpst, tmpen;
		ans = tmpsum = s[1], st = en = tmpst = tmpen = 1;
		rep(j, 2, n)
		{
			if(tmpsum >= 0)
			{
				tmpsum += s[j];
				tmpen = j;
			}
			else
			{
				tmpsum = s[j];
				tmpst = tmpen = j;
			}
			if(tmpsum > ans)
			{
				ans = tmpsum;
				st = tmpst, en = tmpen;
			}
		}
		printf("Case %d:\n%d %d %d\n", i, ans, st, en);
		if(i != test)
			putchar('\n');
	}


	return 0;
}