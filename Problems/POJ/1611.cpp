#include<cstdio>
#include<algorithm>

using namespace std;

#define rep(a, b) for(int i = a; i <= b; i++)

const int MAX = 3 * 1e4 + 10;
const int INF = 0x3f3f3f3f;

int father[MAX];

void init(int n)
{
	rep(0, n - 1)
		father[i] = i;
	return;
}

int find_father(int x)
{
	while(x != father[x])
		x = father[x] = find_father(father[x]);
	return x;
}

void union_set(int x, int y)
{
	int fx = find_father(x);
	int fy = find_father(y);
	if(fx != fy)
		father[fy] = fx;
	return;
}

int get_ans(int n)
{
	int judge = find_father(0);
	int ans = 0;
	rep(0, n - 1)
		if(find_father(i) == judge)
			ans++;
	return ans;
}

int main()
{
	int n, group;
	while(~scanf("%d%d", &n, &group))
	{
		if(!n && !group)
			break;
		init(n);
		while(group--)
		{
			int num;
			scanf("%d", &num);
			if(num == 1)
				scanf("%d", &num);
			else if(num >= 2)
			{
				int pre;
				scanf("%d", &pre);
				rep(1, num - 1)
				{
					int now;
					scanf("%d", &now);
					union_set(pre, now);
					pre = now;
				}
			}
		}
		printf("%d\n", get_ans(n));
	}
	return 0;
}