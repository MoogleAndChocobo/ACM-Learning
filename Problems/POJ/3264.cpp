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

const int MAX = 5 * 1e5 + 10;
const int INF = 0x3f3f3f3f;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a, b) memset(a, b, sizeof(a))

int s[MAX], org[MAX], p[MAX];

int lowbit(int x)
{
	return x & (-x);
}

int getans(int l, int r)
{
	int mx = org[r], mn = org[r];
	while(r >= l)
	{
		mx = max(mx, org[r]);
		mn = min(mn, org[r]);
		for(--r; l < r - lowbit(r); r -= lowbit(r))
		{
			mx = max(mx, s[r]);
			mn = min(mn, p[r]);
		}
	}
	return mx - mn;
}

void init(int pos, int n)
{
	s[pos] = p[pos] = org[pos];
	for(int i = pos - 1; i > pos - lowbit(pos); i -= lowbit(i))
	{
		s[pos] = max(s[pos], s[i]);
		p[pos] = min(p[pos], p[i]);
	}
	return;
}

int main()
{
    
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif    //LOCAL

	int n, test;
	scanf("%d%d", &n, &test);
	rep(i, 1, n)
		p[i] = INF;
	rep(i, 1, n)
	{
		scanf("%d", &org[i]);
		init(i, n);
	}
	while(test--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", getans(l, r));
	}
    return 0;
}
