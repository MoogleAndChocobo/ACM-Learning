//~ #define LOCAL

#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<cctype>
#include<set>
#include<queue>
#include<vector>
#include<map>

using namespace std;

#define rep(i, a, b) for(int i = a; i <= b; i++)

typedef long long LL;
typedef unsigned long long ULL;

const int MAX = 1e3 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int main()
{
	
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	int t;
	scanf("%d", &t);
	while(t--)
	{
		int p, q, x, y, a, b, m, n;
		scanf("%1d%1d%1d%1d-%1d%1d-%1d%1d", &p, &q, &x, &y, &a, &b, &m, &n);
		int year = p * 1000 + q * 100 + x * 10 + y;
		int month = a * 10 + b;
		int day = m * 10 + n;
		if(month == 2 && day == 29)
			printf("-1\n");
		else
		{
			int tmp = 0;
			if(((year % 4 == 0 && year % 100) || year % 400 == 0) && month <= 2)
				tmp++;
			int ge = year + 18;
			if(((ge % 4 == 0 && ge % 100) || ge % 400 == 0) && month >= 3)  
				tmp++;
			rep(i, year + 1, year + 17)
			{
				if(((i % 4 == 0 && i % 100) || i % 400 == 0))
					tmp++;
			}
			int ans = 365 * 18 + tmp;
			printf("%d\n", ans);
		}
	}
	return 0;
}