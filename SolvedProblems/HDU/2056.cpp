#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof(a))
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define sfi(a) scanf("%d", &a)

const int MAX = 1e4 + 5;
const int N = 1e4;

struct Node
{
	double x1, y1, x2, y2;
};

int main()
{

	Node a, b;
	while(~scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &a.x1, &a.y1, &a.x2, &a.y2, &b.x1, &b.y1, &b.x2, &b.y2))
	{
		if((a.x1 >= b.x1 && a.x1 >= b.x2 && a.x2 >= b.x1 && a.x2 >= b.x2) || (b.x1 >= a.x1 && b.x1 >= a.x2 && b.x2 >= a.x1 && b.x2 >= a.x2) || (a.y1 >= b.y1 && a.y1 >= b.y2 && a.y2 >= b.y1 && a.y2 >= b.y2) || (b.y1 >= a.y1 && b.y1 >= a.y2 && b.y2 >= a.y1 && b.y2 >= a.y2))
		{
			puts("0.00");
			continue;
		}

		double x[MAX], y[MAX];
		x[1] = a.x1, x[2] = a.x2, x[3] = b.x1, x[4] = b.x2;
		y[1] = a.y1, y[2] = a.y2, y[3] = b.y1, y[4] = b.y2;

		sort(x + 1, x + 5);
		sort(y + 1, y + 5);

		printf("%.2lf\n", (x[3] - x[2]) * (y[3] - y[2]));
	}
	return 0;
}