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
const int N = 1e6;
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

int main()
{
	
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif	//LOCAL

	//ios::sync_with_stdio(false);
	//cin.tie(0);

	int test;
	sfi(test);
	while(test--)
	{
		char tmp[MAX] = {0};
		sfs(tmp);
		string s = tmp;
		int len = s.size();
		LL a = 0, b = 0;
		if(s[len - 1] != ')')
		{
			LL mypow = 1;
			dow(i, len - 1, 2)
			{
				a += (s[i] - '0') * mypow;
				mypow *= 10;
			}
			b = mypow;
			LL tmpnum = gcd(a, b);
			printf("%lld/%lld\n", a / tmpnum, b / tmpnum);
		}
		else
		{
			int idx = 0;
			rep(i, 2, len - 1)
			{
				if(s[i] == '(')
				{
					idx = i - 1;
					break;
				}
			}
			LL powa = 1;
			LL num = 0;
			dow(i, idx, 2)
			{
				num += (s[i] - '0') * powa;
				powa *= 10;
			}
			//printf("%lld\n", num);
			LL powb = 1;
			LL numm = 0;
			dow(i, len - 2, idx + 2)
			{
				numm += (s[i] - '0') * powb;
				powb *= 10;
			}
			b = powb * powa - powa;
			a = num * powb + numm - num;
			//printf("%lld %lld\n", a, b);
			LL now = gcd(a, b);
			printf("%lld/%lld\n", a / now, b / now);
		}
	}
	
	return 0;
}