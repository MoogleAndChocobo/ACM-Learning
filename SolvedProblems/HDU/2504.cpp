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

int gcd(int a, int b)
{
	while(b)
	{
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
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
		int a, b;
		scanf("%d%d", &a, &b);
		for(int j = b + b; j <= N; j += b)
		{
			if(gcd(a, j) == b)
			{
				printf("%d\n", j);
				break;
			}
		}
	}
	return 0;
}