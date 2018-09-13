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

const int MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))

int s[MAX];

int main()
{

#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	//ios::sync_with_stdio(false);
	//cin.tie(0);

	int test;
	while(~scanf("%d", &test))
	{
		while(test--)
		{
			mem(s);
			int n;
			scanf("%d", &n);
			int cnt = 0;
			while(n != 1)
			{
				if(n & 1)
				{
					if(n != 1)
						s[cnt++] = n;
					n = n * 3 + 1;
				}
				else
					n /= 2;
			}
			if(cnt == 0)
				printf("No number can be output !\n");
			else
			{
				rep(i, 0, cnt - 1)
				{
					printf("%d", s[i]);
					if(i != cnt - 1)
						printf(" ");
					else
						printf("\n");
				}
			}
		}
	}
	return 0;
}