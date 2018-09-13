//~ #define LOCAL

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<iostream>
#include<cmath>
#include<cctype>
#include<vector>
#include<set>
#include<queue>

using namespace std;

typedef long long LL;

const int MAX = 1e3 + 10;
const int N = 1e3;
const int INF = 0x3f3f3f3f;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define pb(a) push_back(a)

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
#endif	//LOCAL

	int m, n;
	while(~scanf("%d%d", &m, &n))
	{
		int a = 0, b = 0, c = 0;
		char opr[MAX];
		sfs(opr);
		int len = strlen(opr);
		rep(i, 0, len - 1)
		{
			if(opr[i] == 'A')
				a = m;
			else if(opr[i] == 'B')
				b = n;
			else if(opr[i] == 'C')
				m = c;
			else if(opr[i] == 'D')
				n = c;
			else if(opr[i] == 'E')
				c = a + b;
			else if(opr[i] == 'F')
				c = a - b;
		}
		printf("%d,%d\n", m, n);
	}
	return 0;
}