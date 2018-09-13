#include<bits/stdc++.h>

using namespace std;

#define rep(a, b) for(int i = a; i <= b; i++)
#define mst(a) memset(a, 0, sizeof(a))

const int MAX = 1e3 + 10;

int father[MAX];

void init(int n)
{
	rep(1, n)
		father[i] = i;
	return;
}

int find_father(int x)
{
	while(x != father[x])
		x = father[x];
	return x;
}

int get_ans(int n)
{
	set<int> store;
	rep(1, n)
		store.insert(find_father(i));
	return store.size();
}

int main()
{
	
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif

	int test;
	scanf("%d", &test);
	while(test--)
	{
		int n, e;
		scanf("%d%d", &n, &e);
		init(n);
		while(e--)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			int fx = find_father(x);
			int fy = find_father(y);
			if(fx != fy)
				father[x] = father[y] = father[fx] = father[fy] = min(fx, fy);
		}
		int ans = get_ans(n);
		printf("%d\n", ans);
	}
	return 0;
}