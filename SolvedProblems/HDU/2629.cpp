//~ #define LOCAL

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<iostream>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<list>
#include<cctype>
#include<ctime>
#include<functional>
#include<cmath>

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

int main()
{
	
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	//ios::sync_with_stdio(false);
	//cin.tie(0);

	int test;
	while(~sfi(test))
	{
		rep(i, 1, test)
		{
			char s[MAX] = {0};
			sfs(s);
			printf("He/She is from ");
			if(s[0] == '3' && s[1] == '3')
				printf("Zhejiang");
			else if(s[0] == '1')
				printf("Beijing");
			else if(s[0] == '7')
				printf("Taiwan");
			else if(s[0] == '8' && s[1] == '1')
				printf("Hong Kong");
			else if(s[0] == '8')
				printf("Macao");
			else if(s[0] == '5')
				printf("Tibet");
			else if(s[0] == '2')
				printf("Liaoning");
			else
				printf("Shanghai");
			printf(",and his/her birthday is on %c%c,%c%c,%c%c%c%c based on the table.\n", s[10], s[11], s[12], s[13], s[6], s[7], s[8], s[9]);
		}
	}
	return 0;
}