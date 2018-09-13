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

const int MAX = 1e3 + 10;
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

LL gcd(LL a, LL b)
{
	LL m = max(a, b);
	LL n = min(a, b);
	while(n)
	{
		LL tmp = m % n;
		m = n;
		n = tmp;
	}
	return m;
}

LL lcm(LL a, LL b)
{
	LL m = max(a, b);
	LL n = min(a, b);
	while(n)
	{
		LL tmp = m % n;
		m = n;
		n = tmp;
	}
	return a * (b / m);
}

void check(LL& m, LL& n)
{
	LL tmp = gcd(m, n);
	m /= tmp;
	n /= tmp;
	return;
}

int main()
{
	
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	//ios::sync_with_stdio(false);
	//cin.tie(0);

	int test;
	cin >> test;
	while(test--)
	{
		char c;
		LL ma, mb, na, nb;
		cin >> ma >> c >> mb >> na >> c >> nb;
		//scanf("%lld/%lld %lld/%lld", &ma, &mb, &na, &nb);
		check(ma, mb);
		check(na, nb);
		LL p = lcm(ma, na);
		LL q = gcd((p / ma) * mb, (p / na) * nb);
		check(p, q);
		if(q != 1)
			cout << p << "/" << q << endl;
			//printf("%lld/%lld\n", p, q);
		else
			cout << p << endl;
			//printf("%lld\n", p);
	}
	return 0;
}