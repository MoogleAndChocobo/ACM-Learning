#include<cstdio>
#include<queue>

using namespace std;

typedef unsigned long long ULL;

ULL bfs(ULL n)
{
	queue<ULL> q;
	q.push(1);
	while(!q.empty())
	{
		ULL cur = q.front();
		q.pop();
		if(cur % n == 0)
			return cur;
		q.push(cur * 10);
		q.push(cur * 10 + 1);
	}
	return 0;
}

int main()
{
	ULL n;
	while(~scanf("%llu", &n))
	{
		if(!n)
			break;
		printf("%llu\n", bfs(n));
	}
}