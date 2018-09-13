//~ #define LOCAL

#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<iostream>
#include<cstdio>

using namespace std;

const int MAX = 1e3 + 10;
const int INF = 0x3f3f3f3f;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof(a))

double dis[MAX];
int casecnt;
map<string, int> mp;

struct Point
{
	int u, v;
	double r;
} s[MAX];

void init(int n)
{
	mem(s);
	mp.clear();
}

bool Bellman(int n, int st, int cnt)
{
	rep(i, 1, n)
		dis[i] = 0;
	dis[st] = 1;
	rep(i, 1, n)
	{
		rep(j, 1, cnt)
		{
			dis[s[j].v] = max(dis[s[j].v], dis[s[j].u] * s[j].r);
		}
	}

	if(dis[st] > 1)
		return true;
	return false;
}

int main()
{

#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	while(cin >> n && n)
	{
		casecnt++;
		rep(i, 1, n)
		{
			string tmp;
			cin >> tmp;
			mp[tmp] = i;
		}
		int road;
		cin >> road;
		rep(i, 1, road)
		{
			string tmpu, tmpv;
			double r;
			cin >> tmpu >> r >> tmpv;
			s[i].u = mp[tmpu];
			s[i].v = mp[tmpv];
			s[i].r = r;
		}

		cout << "Case " << casecnt << ": ";
		rep(i, 1, n)
		{
			if(Bellman(n, i, road))
			{
				cout << "Yes" << endl;
				break;
			}
			if(i == n)
				cout << "No" << endl;
		}
	}
	return 0;
}