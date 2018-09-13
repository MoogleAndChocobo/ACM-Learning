#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

const int MAX = 2 * 1e5 + 10;

int vis[MAX] = {0};
bool tim[MAX] = {0};

int main()
{
	int st, en;
	while(~scanf("%d%d", &st, &en))
	{
		memset(tim, 0, sizeof(tim));
		queue<int> q;
		q.push(st);
		tim[st] = true;
		while(!q.empty())
		{
			int cur = q.front();
			q.pop();
			if(cur == en)
				break;
			if(cur * 2 <= en * 2 && !tim[cur * 2])
			{
				q.push(cur * 2);
				vis[cur * 2] = vis[cur] + 1;
				tim[cur * 2] = true;
			}
			if(cur + 1 <= en && !tim[cur + 1])
			{
				q.push(cur + 1);
				vis[cur + 1] = vis[cur] + 1;
				tim[cur * 2] = true;
			}
			if(cur - 1 >= 0 && !tim[cur - 1])
			{
				q.push(cur - 1);
				vis[cur - 1] = vis[cur] + 1;
				tim[cur - 1] = true;
			}
		}
		printf("%d\n", vis[en]);
	}
	return 0;
}