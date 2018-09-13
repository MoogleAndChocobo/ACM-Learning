#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define mem(a) memset(a, 0, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define sfs(a) scanf("%s", a)

const int MAX = 1e3 + 5;
const int N = 1e3;

struct Node
{
	int x, y;
	Node(int xx = 0, int yy = 0):x(xx), y(yy){}
	friend bool operator <(Node a, Node b)
	{
		return a.x > b.x;
	}
};

int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n;
	while(~sfi(n))
	{
		vector<Node> vec;
		int lmt = 2 * n - 1;
		rep(i, n + 1, lmt)
		{
			int x = (n * i) / (i - n);
			if(x * i == n * (x + i))
				if(i <= x)
					vec.push_back(Node(x, i));
		}
		vec.push_back(Node(n * 2, n * 2));
		int len = vec.size();
		printf("%d\n", len);
		rep(i, 0, len - 1)
			printf("1/%d = 1/%d + 1/%d\n", n, vec[i].x, vec[i].y);
	}
	return 0;
}