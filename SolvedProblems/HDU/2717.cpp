#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

typedef long long LL;
typedef long long ll;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define mem(a) memset(a, 0, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define sync ios::sync_with_stdio(0); cin.tie(0);

const int MAX = 2e6 + 5;

int m, n;

int vis[MAX];

int bfs()
{
	queue<int> q;
	q.push(m);
	while(!q.empty())
	{
		int cur = q.front();
		q.pop();
		if(cur == n)
			return vis[cur];
		if(cur - 1 >= 0 && !vis[cur - 1])
			q.push(cur - 1), vis[cur - 1] = vis[cur] + 1;
		if(cur + 1 <= 3 * n && !vis[cur + 1])
			q.push(cur + 1), vis[cur + 1] = vis[cur] + 1;
		if(cur * 2 <= 3 * n && !vis[2 * cur])
			q.push(2 * cur), vis[2 * cur] = vis[cur] + 1;
		vis[m] = 1;
	}
	return -1;
}

int main()
{
	while(~scanf("%d%d", &m, &n))
	{
		mem(vis);
		printf("%d\n", bfs());
	}
	return 0;
}