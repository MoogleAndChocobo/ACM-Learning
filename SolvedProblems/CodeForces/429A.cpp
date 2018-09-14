//~ #define LOCAL

#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<iostream>
#include<cmath>

using namespace std;

const int MAX = 1e5 + 10;

#define rep(i, a, b) for(int i = a; i <= b; i++)

bool vis[MAX];
int prt[MAX], cnt[MAX];
bool org[MAX], aim[MAX];

vector<int> ans;
vector<int> e[MAX];

void Bfs(int st)
{
	queue<int> q;
	q.push(st);
	vis[st] = true;

	while(!q.empty())
	{ 
		int cur = q.front();
		q.pop();
		if(prt[cur] && prt[prt[cur]])
		{
			if((cnt[prt[prt[cur]]] % 2 == 0 && org[cur] == aim[cur]) || (cnt[prt[prt[cur]]] % 2 != 0 && org[cur] != aim[cur]))
				cnt[cur] = cnt[prt[prt[cur]]];
			else
			{
				cnt[cur] = cnt[prt[prt[cur]]] + 1;
				ans.push_back(cur);
			}
		}
		else if (org[cur] != aim[cur])
		{
			cnt[cur] = 1;
			ans.push_back(cur);
		}
		else
			cnt[cur] = 0;
		int len = e[cur].size();
		rep(i, 0, len - 1)
		{
			if(!vis[e[cur][i]])
			{
				vis[e[cur][i]] = true;
				q.push(e[cur][i]);
				prt[e[cur][i]] = cur;
			}
		}
	}
}



int main() 
{

#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	int n;
	scanf("%d", &n);

	rep(i, 1, n - 1)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	rep(i, 1, n)
		scanf("%d", &org[i]);
	rep(i, 1, n)
		scanf("%d", &aim[i]);
		
	Bfs(1);

	int len = ans.size();
	printf("%d\n", len);
	rep(i, 0, len - 1)
		printf("%d\n", ans[i]);
		
	return 0;
}