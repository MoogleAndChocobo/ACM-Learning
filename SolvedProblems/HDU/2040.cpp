//~ #define LOCAL

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<cctype>
#include<queue>
#include<set>
#include<vector>
#include<map>
#include<iostream>
#include<ctime>
#include<list>
#include<functional>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int MAX = 1e3 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))

int main()
{

#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	//ios::sync_with_stdio(false);
	//cin.tie(0);

	int n;
	scanf("%d", &n);
	while(n--)
	{
		bool flag = false;
		int a, b;
		scanf("%d%d", &a, &b);
		LL sum = 0;
		rep(i, 1, a - 1)
		{
			if(a % i == 0)
				sum += (LL)i;
		}
		if(sum == b)
		{
			flag = true;
		}
		sum = 0;
		rep(i, 1, b - 1)
		{
			if(b % i == 0)
				sum += (LL)i;
		}
		if(flag && sum == a)
		{
			printf("YES\n");
			continue;
		}
		printf("NO\n");
	}
	return 0;
}