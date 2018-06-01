#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <functional>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define sfd(a) scanf("%l", &a)
#define sfu(a) scanf("%llu", &a)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define pb(a) push_back(a)

const int MAX = 5e5 + 50;
const int N = 1e3;
const int MOD = 1e9 + 7;

LL a[MAX], b[MAX];

LL inversed_pair(int l, int r)
{
	LL sum = 0;
	int mid = (l + r) / 2, i = l, j = mid + 1, k = l;
	
	if (l < mid)
		sum += inversed_pair(l, mid);
	if (mid + 1 < r)
		sum += inversed_pair(mid + 1, r);
	
	while (i <= mid || j <= r)
	{
		while (i <= mid && (j > r || a[i] <= a[j]))
			b[k++] = a[i++];
		while (j <= r && (i > mid || a[j] < a[i]))
		{
			b[k++] = a[j++];
			sum += mid - i + 1;
		}
	}
	rep(i, l, r)
		a[i] = b[i];
	return sum;
}

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
	//~ freopen("out.txt", "r" , stdout);
#endif

	int n;
	while(~sfi(n) && n)
	{
		mem(a), mem(b);
		rep(i, 0, n - 1)
			sfl(a[i]);
		printf("%lld\n", inversed_pair(0, n - 1));
	}
	return 0;
}
