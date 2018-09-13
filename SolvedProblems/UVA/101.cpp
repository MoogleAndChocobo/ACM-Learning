#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <bitset>
#include <deque>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define sfs(a) scanf("%s", a)
#define pb(a) push_back(a)
#define sync ios::sync_with_stdio(0); cin.tie(0);

const int MAX = 1e2 + 5;
const int L = 2;
const LL MOD = 10000;
const int dir[MAX][MAX] = {{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,1},{1,-1}};

vector<int> vec[MAX];
int n;

void Show()
{
	rep(i, 0, n - 1)
	{
		cout << i << ":";
		int len = vec[i].size();
		rep(j, 0, len - 1)
			cout << " " << vec[i][j];
		cout << "\n";
	}
}

void Origin(int x)
{
	vector<int> rec;
	rep(i, 0, n - 1)
	{
		int len = vec[i].size();
		rep(j, 0, len - 1)
		{
			if(vec[i][j] == x)
			{
				rep(k, j + 1, len - 1)
				{
					int now = vec[i][k];
					rec.pb(now);
				}
				vec[i].resize(j + 1);
				int l = rec.size();
				rep(k, 0, l - 1)
					vec[rec[k]].pb(rec[k]);
				return;
			}
		}
	}
}

int Find(int x)
{
	rep(i, 0, n - 1)
	{
		int len = vec[i].size();
		rep(j, 0, len - 1)
		{
			if(vec[i][j] == x)
				return i;
		}
	}
	return 0;
}

void Pile(int x, int idx)
{
	vector<int> rec;
	rep(i, 0, n - 1)
	{
		int len = vec[i].size();
		rep(j, 0, len - 1)
		{
			if(vec[i][j] == x)
			{
				rep(k, j, len - 1)
				{
					int now = vec[i][k];
					rec.pb(now);
				}
				vec[i].resize(j);
				int l = rec.size();
				rep(i, 0, l - 1)
					vec[idx].pb(rec[i]);
				return;
			}
		}
	}
}

void MoveOnto(int x, int y)
{
	if(Find(x) == Find(y))
		return;
	Origin(x);
	Origin(y);
	int fx = Find(x), fy = Find(y);
	if(fx == fy && x == y)
		return;
	vec[fx].pop_back();
	vec[fy].pb(x);
}

void MoveOver(int x, int y)
{
	if(Find(x) == Find(y))
		return;
	Origin(x);
	int fx = Find(x), fy = Find(y);
	if(fx == fy && x == y)
		return;
	vec[Find(x)].pop_back();
	vec[Find(y)].pb(x);
}

void PileOnto(int x, int y)
{
	if(Find(x) == Find(y))
		return;
	Origin(y);
	Pile(x, Find(y));
}

void PileOver(int x, int y)
{
	if(Find(x) == Find(y))
		return;
	Pile(x, Find(y));
}

int main()
{	
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif

	cin >> n;
	string opr;
	rep(i, 0, n - 1)
		vec[i].pb(i);
	while(cin >> opr && opr != "quit")
	{	
		int x, y;
		string turn;
		cin >> x >> turn >> y;
		if(opr == "move" && turn == "over")
			MoveOver(x, y);
		else if(opr == "move" && turn == "onto")
			MoveOnto(x, y);
		else if(opr == "pile" && turn == "over")
			PileOver(x, y);
		else
			PileOnto(x, y);
	}
	Show();
	return 0;
}