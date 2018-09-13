#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<iostream>
#include<vector>
#include<sstream>
#include<map>
#include<set>
#include<cmath>
#include<cctype>
#include<functional>
#include<ctime>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LF;

const int MAX = 1e5 + 10;
const int N = 1e3;
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f;

#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%ld", &a)
#define sfs(a) scanf("%s", a)
#define sfc(a) getchar(a)
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))

struct Node
{
	int num;
	bool vis;
	friend bool operator <(Node a, Node b)
	{
		return a.num < b.num;
	}
};

int main()
{
	
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	int dragon, n;
	while(~scanf("%d%d", &dragon, &n))
	{
		if(dragon == 0 && n == 0)
			break;
		Node d[MAX], k[MAX];
		rep(i, 1, dragon)
		{
			sfi(d[i].num);
			d[i].vis = false;
		}
		rep(i, 1, n)
		{
			sfi(k[i].num);
			k[i].vis = false;
		}
		if(n < dragon)
		{
			printf("Loowater is doomed!\n");
			continue;
		}
		sort(d + 1, d + dragon + 1);
		sort(k + 1, k + n + 1);
		int ans = 0, cnt = 0;
		bool flag = false;
		rep(i, 1, n)
		{
			dow(j, dragon, 1)
			{
				if(!d[j].vis && d[j].num <= k[i].num)
				{
					cnt++;
					d[j].vis = k[i].vis = true;
					ans += k[i].num;
					break;
				}
			}
			if(cnt == dragon)
			{
				flag = true;
				break;
			}
		}
		if(flag)
			printf("%d\n", ans);
		else
			printf("Loowater is doomed!\n");
	}
	return 0;
}