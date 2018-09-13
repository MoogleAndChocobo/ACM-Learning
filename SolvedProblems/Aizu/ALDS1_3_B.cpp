#include<cstdio>
#include<queue>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)

const int MAX = 20;

struct Point
{
	char name[MAX];
	int timeneeded;
};

queue<Point> q;

int main()
{
	int n, per;
	scanf("%d%d", &n, &per);
	{
		FOR(i, 1, n)
		{
			Point tmp;
			scanf("%s%d", tmp.name, &tmp.timeneeded);
			q.push(tmp);
		}

		int sum = 0;
		while(!q.empty())
		{
			Point cur = q.front();
			q.pop();
			if(cur.timeneeded <= per)
			{
				sum += cur.timeneeded;
				printf("%s %d\n", cur.name, sum);
			}
			else
			{
				sum += per;
				cur.timeneeded -= per;
				q.push(cur);
			}
		}
	}
	return 0;
}