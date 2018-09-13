#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#include<set>
#include<map>
#include<cmath>

using namespace std;

const int MAX = 1e3 + 10;
const int INF = 0x3f3f3f3f;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))

double g[MAX][MAX];
double mst[MAX][MAX];

struct Point
{
	int x, y, p;
} point[MAX];

void init(int n)
{
	rep(i, 1, n)
	{
		rep(j, i, n)
		{
			g[i][j] = g[j][i] = INF;
			mst[i][j] = mst[j][i] = 0;
		}
	}
	mem(point);
	return;
}

double getlen(int x1, int y1, int x2, int y2)
{
	return sqrt((double)(x1 - x2) * (double)(x1 - x2) + (double)(y1 - y2) * (double)(y1 - y2));
}

double Prim(int n)
{
	double sum = 0, ans = 0;
	vector<int> v;
	double dis[MAX] = {0};
	bool vis[MAX] = {0};
	int prt[MAX] = {0};

	rep(i, 1, n)
		dis[i] = INF;
	dis[1] = 0;
	v.push_back(1);
	vis[1] = true;
	int cur = 1;
	
	rep(i, 1, n - 1)
	{
		rep(j, 1, n)
		{
			if(!vis[j] && g[cur][j] < dis[j])
				prt[j] = cur, dis[j] = g[cur][j];
		}
		double mi = INF;
		int idx = 0;
		rep(j, 1, n)
		{
			if(!vis[j] && dis[j] < mi)
			{
				mi = dis[j];
				idx = j;
			}
		} 
		sum += dis[idx];
		cur = idx;
		vis[idx] = true;

		int len = v.size();
		rep(j, 0, len - 1)
			mst[v[j]][idx] = mst[idx][v[j]] = max(mst[v[j]][prt[idx]], dis[idx]);
		v.push_back(idx);
	}
	rep(i, 1, n)
	{
		rep(j, i + 1, n)
		{
			ans = max(ans, (double)(point[i].p + point[j].p) / (sum - mst[i][j]));
		}
	}
	return ans;
}

int main()
{
	
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	int test;
	scanf("%d", &test);
	while(test--)
	{
		int n;
		scanf("%d", &n);
		init(n);
		rep(i, 1, n)
		{
			scanf("%d%d%d", &point[i].x, &point[i].y, &point[i].p);
		}

		rep(i, 1, n)
		{
			rep(j, 1, i - 1)
			{
				g[i][j] = g[j][i] = getlen(point[i].x, point[i].y, point[j].x, point[j].y);
			}
		}

		printf("%.2lf\n", Prim(n));
	}
	return 0;
}