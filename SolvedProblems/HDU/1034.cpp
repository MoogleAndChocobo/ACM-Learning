#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cctype>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define sfs(a) scanf("%s", a)

const int MAX = 1e5 + 5;
const int N = 1e3;

int s[MAX];
int tmp[MAX];

bool check(int n)
{
	rep(i, 2, n)
		if(s[i] != s[1])
			return false;
	return true;
}

void solve(int n)
{
	rep(i, 1, n)
		if(s[i]&1)
			s[i]++;
}

int main()
{
	int n;
	while(~sfi(n) && n)
	{
		mem(s), mem(tmp);
		rep(i, 1, n)
			sfi(s[i]);
		
		int cnt = 0;
		while(!check(n))
		{
			cnt++;
			mem(tmp);
			rep(i, 2, n)
				tmp[i] = s[i] / 2 + s[i - 1] / 2;
			tmp[1] = s[1] / 2 + s[n] / 2;
			rep(i, 1, n)
				s[i] = tmp[i];
			solve(n);
		}
		printf("%d %d\n", cnt, s[1]);
	}
	return 0;
}