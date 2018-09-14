#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof(a))

const int MAX = 1e4 + 10;

struct Node
{
	int num;
	int l, r;
	friend bool operator <(Node a, Node b)
	{
		if(a.l != b.l)
			return a.l < b.l;
		else
			return a.num < b.num;
	}
} st[MAX];

bool vis[MAX] = {0};
int loc[MAX] = {0};

int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		mem(st), mem(vis), mem(loc);
		int n;
		int mx = 0;
		scanf("%d", &n);
		rep(i, 1, n)
		{
			st[i].num = i;
			scanf("%d%d", &st[i].l, &st[i].r);
			mx = max(mx, st[i].r);
		}
		sort(st + 1, st + n + 1);
		
		int time = 1;
		while(time <= mx)
		{
			int cnt = 1;
			while(!(st[cnt].l <= time && st[cnt].r >= time) || vis[cnt])
			{
				if(cnt == n)
				{
					break;
				}
				cnt++;
			}
			if(!vis[cnt] && st[cnt].l <= time && st[cnt].r >= time)
			{
				loc[st[cnt].num] = time;
				vis[cnt] = true;
			}
			time++;
		}
		rep(i, 1, n)
		{
			printf("%d", loc[i]);
			if(i != n)
				printf(" ");
			else
				printf("\n");
		}
	}
	return 0;
}