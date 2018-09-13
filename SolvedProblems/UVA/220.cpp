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
#define dow(i, a, b) for(int i = a; i <= b; ++j)
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

char pic[MAX][MAX];

struct Node
{
	int x, y;
	Node(int xx = 0, int yy = 0):x(xx), y(yy){}
	friend bool operator ==(Node a, Node b)
	{
		return a.x == b.x && a.y == b.y;
	}
	friend bool operator <(Node a, Node b)
	{
		if(a.x != b.x)
			return a.x < b.x;
		return a.y < b.y;
	}
};

void oprQ();
void oprL();
void oprM(int &now);
void checkper(int dx, int dy, int now, set<Node> &ans);
bool inpic(int x, int y);
bool islegal(int x, int y, int now);


void oprQ()
{
	rep(i, 1, 8)
	{
		rep(j, 1, 8)
		{
			cout << pic[i][j];
		}
		putchar('\n');
	}
}

void oprM(int &now)
{
	int tmp;
	cin >> tmp;
	int x = tmp / 10, y = tmp % 10;
	if(islegal(x, y, now))
		;
	else if(islegal(x, y, !now))
		now = !now;
		
	int cw = 0, cb = 0;
	rep(i, 1, 8)
		rep(j, 1, 8)
			if(pic[i][j] == 'W')
				cw++;
			else if(pic[i][j] == 'B')
				cb++;
	printf("Black -%s%d White -%s%d\n", (cb >= 10) ? " " : "  ", cb, (cw >= 10) ? " " : "  ", cw);
}

bool islegal(int x, int y, int now)
{
	bool vis[10][10] = {0};
	bool ans = false;
	rep(i, 0, 7)
	{
		int nowx = x, nowy = y;
		bool f = false;
		while(inpic(nowx, nowy))
		{
			nowx += dir[i][0];
			nowy += dir[i][1];
			if((now == 1 && pic[nowx][nowy] == 'B') || (now == 0 && pic[nowx][nowy] == 'W'))
				f = true;
			else
				break;
		}
		if(f)
			f = inpic(nowx, nowy);
		if(f)
			f = (now == 1 && pic[nowx][nowy] == 'W') || (now == 0 && pic[nowx][nowy] == 'B');
		if(f)
		{
			for(int xx = x, yy = y; xx != nowx || yy != nowy; xx += dir[i][0], yy += dir[i][1])
				vis[xx][yy] = true;
			vis[x][y] = true;
			ans = true;
		}
	}
	rep(i, 1, 8)
		rep(j, 1, 8)
			if(vis[i][j])
				pic[i][j] = (now == 1 ? 'W' : 'B');
	return ans;
}

void oprL(int now)
{
	set<Node> ans;
	ans.clear();
	rep(i, 1, 8) rep(j, 1, 8)
	{
		if(((now == 1 && pic[i][j] == 'W') || (now == 0 && pic[i][j] == 'B')))
		{
			checkper(i, j, now, ans);
		}
	}
	int len = ans.size();
	int i = 0;
	bool f = false;
	for(set<Node>::iterator it = ans.begin(); it != ans.end(); i++, it++)
	{
		cout << "(" << (*it).x << "," << (*it).y << ")";
		cout << (i != len - 1 ? ' ' : '\n');
		f = true;
	}
	if(!f)
		puts("No legal move.");
}

void checkper(int dx, int dy, int now, set<Node> &ans)
{
	rep(i, 0, 7)
	{
		int nowx = dx, nowy = dy;
		bool f = false;
		while(inpic(nowx, nowy))
		{
			nowx += dir[i][0];
			nowy += dir[i][1];
			if((now == 1 && pic[nowx][nowy] == 'B') || (now == 0 && pic[nowx][nowy] == 'W'))
				f = true;
			else
				break;
		}
		if(f)
			f = inpic(nowx, nowy);
		if(f)
			f = pic[nowx][nowy] == '-';
		if(f)
			ans.insert(Node(nowx, nowy));
	}
}



bool inpic(int x, int y)
{
	return x >= 1 && x <= 8 && y >= 1 && y <= 8;
}

int main()
{
	//~ freopen("in.txt", "r", stdin);
	//~ sync
	
	int T;
	cin >> T;
	rep(kase, 1, T)
	{
		
		rep(i, 1, 8)
			rep(j, 1, 8)
				cin >> pic[i][j];
				
		int now = 0;
		char tmp;
		cin >> tmp;
		if(tmp == 'W')
			now = 1;
		char opr;
		while(cin >> opr)
		{
			if(opr == 'Q')
			{
				oprQ();
				break;
			} 
			else if(opr == 'M')
			{
				oprM(now);
				now = !now;
			}
			else
			{
				oprL(now);
			}
		}
		if(kase != T)
			putchar('\n');
	}
	return 0;
}