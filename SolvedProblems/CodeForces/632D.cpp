#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <cctype>
#include <iostream>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define sfd(a) scanf("%lf", &a)
#define pb(a) push_back(a)

const int MAX = 1e6 + 5;
const int N = 100;

bool vis[MAX];
int s[MAX];
vector<int> ans[MAX];
vector<int> v[15];
vector<int> vec;
int ll[15];



int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
	//~ freopen("out.txt", "w", stdout);
#endif

	int n, m;
	scanf("%d%d", &n, &m);
	rep(i, 1, n)
		sfi(s[i]);
	
	rep(i, 1, n)
	{
		if(s[i] <= 10)
			v[s[i]].push_back(i);
		else if(s[i] <= m)
		{
			for(int j = s[i]; j <= m; j += s[i])
				ans[j].push_back(i);
		}
	}
	
	//~ rep(i, 1, m)
		//~ printf("%d\n", (int)ans[i].size());
	
	rep(i, 1, 10)
		ll[i] = v[i].size();

	
	int cur = 0, mx = 0, idx = 0;
	rep(i, 1, m)
	{
		int now = 0;
		rep(j, 1, 10)
			if(i % j == 0 && ll[j])
				now += ll[j];
		int l = ans[i].size();
		if(l + now > cur)
		{
			cur = l + now, idx = i, mx = l;
		}
	}
	
	if(idx == 0)
		idx = 1;
	printf("%d %d\n", idx, cur);
	
	rep(i, 1, 10)
		if(idx % i == 0 && ll[i])
			rep(j, 0, ll[i] - 1)
				vec.push_back(v[i][j]);
	sort(vec.begin(), vec.end());
	
	int len = vec.size();
	bool flag = false;
	int ord = 0;
	rep(i, 0, mx - 1)
	{
		while(ord < len && vec[ord] < ans[idx][i])
		{
			if(flag)
				putchar(' ');
			flag = true;
			printf("%d", vec[ord]);
			ord++;
		}
		if(flag)
			putchar(' ');
		flag = true;
		printf("%d", ans[idx][i]);
	}
	rep(i, ord, len - 1)
	{
		if(flag)
			putchar(' ');
		flag = true;
		printf("%d",vec[i]);
	}
	putchar('\n');
	return  0;
}