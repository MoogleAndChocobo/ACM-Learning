#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cctype>
#include <iostream>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i > =b; --i)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define sfs(a) scanf("%s", a)
#define pb(a) push_back(a)
#define all(a) a.begin(),a.end()

const int MAX = 1e5 + 5;
const int INF = 1e5;

int s[MAX];
int cnt[MAX];

int main()
{
	int n;
	sfi(n);
	rep(i, 1, n)
		sfi(s[i]);
	int mx1 = 0, mx2 = 0;
	rep(i, 1, n)
	{
		if(s[i] > mx1)
		{
			mx2 = mx1;
			mx1 = s[i];
			cnt[s[i]]--;
		}
		else if(s[i] > mx2)
		{
			cnt[mx1]++;
			mx2 = s[i];
		}
	}
	cnt[0] = -10000000;
	int idx = 0;
	rep(i, 1, n)
		if(cnt[i] > cnt[idx])
			idx = i;
	printf("%d\n", idx);
	return 0;
}