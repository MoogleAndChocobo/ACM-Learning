//~ #define LOCAL

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<set>
#include<iostream>

using namespace std;

//#pragma comment(linker, "/STACK:102400000, 102400000/")

const int MAX = 1e3 + 1;
const int INF = 0x3f3f3f3f;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))

int main()
{
    
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif    //LOCAL

	int test;
	scanf("%d", &test);
	rep(i, 1, test)
	{
		int n = 1, ans = 1;
		scanf("%d", &n);
		double rate = 1;
		dow(j, n, 1)
		{
			rate *= (double)j / (double)n;
			if(1 - rate >= 0.5)
			{
				ans = n - j;
				break;
			}
		}
		printf("Case %d: %d\n", i, ans);
	}
    return 0;
}
