//~ #define LOCAL

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<set>
#include<cmath>
#include<vector>
#include<cctype>
#include<iostream>
#include<sstream>
#include<string>
#include<functional>
#include<list>
#include<ctime>

using namespace std;

//#pragma comment(linker, "/STACK:102400000, 102400000/")

typedef long long			LL;
typedef unsigned long long	ULL;
typedef pair<int, int>		pii;

const int MAX = 1e3 + 10;
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

#define sfi(a)			scanf("%d", &a)
#define sfd(a)			scanf("%lf", &a)
#define sfl(a)			scanf("%lld", &a)
#define sfs(a)			scanf("%s", a);
#define rep(i, a, b)	for(int i = a; i <= b; i++)
#define dow(i, a, b)	for(int i = a; i >= b; i--)
#define mem(a)			memset(a, 0, sizeof(a))
#define mst(a, b)		memset(a, b, sizeof(a))

int itool(void);
LL lltool(void);

void init(int n)
{
	
	return;
}

int main()
{
	
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	//ios::sync_with_stdio(false);
	//cin.tie(0);

	LL a, b;
	while(~scanf("%lld%lld", &a, &b))
	{
		while(a && b)
		{
			if(a >= b + b)
			{
				LL cnt = a / (b + b);
				a -= cnt * (b + b);
			}
			else if(b >= a + a)
			{
				LL cnt = b / (a + a);
				b -= cnt * (a + a);
			}
			else
				break;
		}
		printf("%lld %lld\n", a, b);
	}
	return 0;
}

int itool(void)
{
	int tmp = 0;
	char c = getchar();
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c))
	{
		tmp = tmp * 10 + c - '0';
		c = getchar();
	}
	return tmp;
}

LL lltool(void)
{
	LL tmp = 0;
	char c = getchar();
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c))
	{
		tmp = tmp * 10 + c - '0';
		c = getchar();
	}
	return tmp;
}