//~ #define LOCAL

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<iostream>
#include<cmath>
#include<cctype>
#include<vector>
#include<set>
#include<queue>

using namespace std;

typedef long long LL;

const int MAX = 1e5 + 10;
const int N = 6e4;
const int INF = 0x3f3f3f3f;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define pb(a) push_back(a)

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
#endif	//LOCAL

	int cnt = 0;
	int n;
	while(~sfi(n) && n)
	{
		int s[MAX] = {0};
		int sum = 0;
		rep(i, 1, n)
		{
			sfi(s[i]);
			sum += s[i];
		}
		sum /= n;
		int ans = 0;
		rep(i, 1, n)
			if(s[i] > sum)
				ans += s[i] - sum;
		printf("Set #%d\nThe minimum number of moves is %d.\n\n", ++cnt, ans);
	}
	return 0;
}