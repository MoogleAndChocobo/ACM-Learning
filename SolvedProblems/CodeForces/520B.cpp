//bfs

#include<bits/stdc++.h>

using namespace std;

#define b_mst(a) memset(a, false, sizeof(a))

const int MAX = 1e5 + 10;

bool vis[MAX] = {0};
int dis[MAX] = {0};
int st, en;

int bfs(void)
{
    b_mst(vis);
    vis[st] = true;
    dis[st] = 0;
    queue<int> que;
    que.push(st);
    while(!que.empty())
    {
        int now = que.front();
        que.pop();
        if(now == en)
            return dis[now];
        if(now < en && !vis[2 * now])
        {
            vis[2 * now] = true;
            dis[2 * now] = dis[now] + 1;
            que.push(2 * now);
        }
        if(now > 1 && !vis[now - 1])
        {
            vis[now - 1] = true;
            dis[now - 1] = dis[now] + 1;
            que.push(now - 1);
        }
    }
}

int main()
{
    while(~scanf("%d%d", &st, &en))
        printf("%d\n", bfs());
    return 0;
}