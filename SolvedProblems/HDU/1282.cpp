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

int check(int n)
{
	int s[MAX] = {0};
	int cnt = 0;
	while(n)
	{
		s[++cnt] = n % 10;
		n /= 10;
	}
	rep(i, 1, cnt)
	{
		n = n * 10 + s[i];
	}
	return n;
}

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
#endif	//LOCAL

	int n;
	while(~sfi(n))
	{
		vector<int> vec;
		int now = check(n);
		while(n != now)
		{
			vec.pb(n);
			n += now;
			now = check(n);
		}
		int len = vec.size();
		printf("%d\n", len);
		rep(i, 0, len - 1)
		{
			printf("%d--->", vec[i]);
		}
		printf("%d\n", n);
	}
	return 0;
}