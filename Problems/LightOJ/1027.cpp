#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <bitset>
#include <deque>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define sfs(a) scanf("%s", a)
#define pb(a) push_back(a)
#define sync ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define all(a) a.begin(),a.end()
#define fr first
#define sc second

const int MAX = 1e2 + 5;
const int L = 2;
const int N = 1500;
const LL MOD = 10000;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
#endif

	int T;
	sfi(T);
	rep(kase, 1, T)
	{
		int n;
		sfi(n);
		
		int ans = 0, cnt = 0;
		
		rep(i, 1, n)
		{
			int tmp;
			sfi(tmp);
			tmp >= 0 ? ans += tmp, cnt++ : ans -= tmp;
		}

		if(cnt == 0)
			printf("Case %d: inf\n", kase);
		else
		{
			int tmp = gcd(ans, cnt);
			printf("Case %d: %d/%d\n", kase, ans / tmp, cnt / tmp);
		}
	}
	return 0;
}