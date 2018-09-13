//~ #define LOCAL

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

const int MAX = 1e4 + 10;
const int INIT = 0;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof(a))

int cnt;
double dis[MAX];

struct Point
{
	int u, v;
	double rate, com;
} s[MAX];

void init(int n)
{
	mem(s);
	mem(dis);
	rep(i, 0, n)
		dis[i] = INIT;
	cnt = 0;
	return;
}

void addedge(int u, int v, double rate, double com)
{
	s[cnt].u = u;
	s[cnt].v = v;
	s[cnt].rate = rate;
	s[cnt++].com = com;
	return;
}

bool Bellman(int n, int st, double num)
{
	dis[st] = num;
	rep(i, 1, n - 1)
	{
		rep(j, 0, cnt - 1)
		{
			int u = s[j].u, v = s[j].v;
			double rate = s[j].rate, com = s[j].com;
			if(dis[v] < (dis[u] - com) * rate)
				dis[v] = (dis[u] - com) * rate;
		}
	}
	rep(i, 0, cnt - 1)
	{
		int u = s[i].u, v = s[i].v;
		double rate = s[i].rate, com = s[i].com;
		if(dis[v] < (dis[u] - com) * rate)
			return true;
	}
	return false;
}

int main()
{

#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	int n, road, st;
	double num;
	while(~scanf("%d%d%d%lf", &n, &road, &st, &num))
	{
		init(n);
		while(road--)
		{
			int u, v;
			double rate, com;
			scanf("%d%d%lf%lf", &u, &v, &rate, &com);
			addedge(u, v, rate, com);
			scanf("%lf%lf", &rate, &com);
			addedge(v, u, rate, com);
		}
		if(Bellman(n, st, num))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}