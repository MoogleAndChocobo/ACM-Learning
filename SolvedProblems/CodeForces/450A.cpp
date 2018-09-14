#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define sfi(a) scanf("%d", &a)

const int MAX = 1e3 + 5;

struct Node
{
	int num, order;
	Node(int num_ = 0, int order_ = 0):num(num_), order(order_){}
};

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	queue<Node> q;
	int s[MAX] = {0};
	for(int i = 1; i <= n; i++)
	{
		sfi(s[i]);
		q.push(Node(0, i));
	}
	int ans = 1;
	while(!q.empty())
	{
		Node now = q.front();
		q.pop();
		ans = now.order;
		now.num += m;
		if(now.num < s[now.order])
			q.push(now);
	}
	printf("%d\n", ans);
	return 0;
}