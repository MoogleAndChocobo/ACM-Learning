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
const int N = 1e9;

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

LL s[MAX];

void init()
{
	LL mypow = 1;
	int cnt = 0;
	while(s[cnt] <= (LL)N)
	{
		cnt++;
		s[cnt] = mypow * mypow * mypow + s[cnt - 1];
		mypow++;
	}
	//~ printf("%d\n", cnt);
}

int main()
{
#ifdef LOCAL
	//~ fli
	//~ flo
#endif	//LOCAL

	init();

	int T;
	sfi(T);
	rep(kase, 1, T)
	{
		LL n;
		sfl(n);
		int pos = lower_bound(s + 1, s + 250 + 1, n) - s;
		printf("%d\n", pos);
	}
	return 0;
}