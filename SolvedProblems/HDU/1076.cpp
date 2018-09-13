#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<iostream>

using namespace std;

typedef long long LL;

const int MAX = 1e2 + 10;
const int N = 200;
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define pb(a) push_back(a)
#define mst(a, b) memset(a, b, sizeof(a))
#define sfl(a) scanf("%lld", &a)

bool check(int n)
{
	return (n % 4 == 0 && n % 100 != 0) || n % 400 == 0;
}

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
#endif	//LOCAL

	//~ ios::sync_with_stdio(false);
	//~ cin.tie(0);

	int T;
	sfi(T);
	rep(i, 1, T)
	{
		int year, need;
		scanf("%d%d", &year, &need);
		int cnt = 0;
		while(cnt < need)
		{
			if(check(year))
				cnt++;
			year++;
		}
		printf("%d\n", year - 1);
	}
	return 0;
}