#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <cmath>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define mem(a) memset(a, 0, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define sfd(a) scanf("%lf", &a)
#define mst(a, b) memset(a, b, sizeof(a))
#define pb(a) push_back(a)
#define all(c) c.begin(), c.end()

const int MAX = 50 + 5;

struct Node
{
	int r, c;
	Node(int rr = 0, int cc = 0):r(rr), c(cc){}
	friend bool operator ==(Node a, Node b)
	{
		return a.r == b.r && a.c == b.c;
	}
};

Node pic[MAX][MAX], tmp[MAX][MAX];
int m, n;
bool checkblank;

void init();
void ex();
void dr();
void dc();
void ir();
void ic();
void print();
void copy();

void copy()
{
	mem(tmp);
	rep(i, 1, m)
		rep(j, 1, n)
			tmp[i][j] = pic[i][j];
}
void init()
{
	rep(i, 1, m)
	{
		rep(j, 1, n)
		{
			pic[i][j] = Node(i, j);
		}
	}
}

void ex()
{
	int r1, c1, r2, c2;
	scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
	swap(pic[r1][c1], pic[r2][c2]);
}

void dr()
{
	int num;
	sfi(num);
	bool vis[MAX] = {0};
	rep(i, 1, num)
	{
		int r;
		sfi(r);
		vis[r] = true;
	}
	vector<int> vec;
	rep(i, 1, m)
		if(!vis[i])
			vec.pb(i);		
	
	copy();
	
	rep(i, 1, m - num)
		rep(j, 1, n)
			pic[i][j] = tmp[vec[i - 1]][j];
	m -= num;
}

void dc()
{
	int num;
	sfi(num);
	bool vis[MAX] = {0};
	rep(i, 1, num)
	{
		int c;
		sfi(c);
		vis[c] = true;
	}
	vector<int> vec;
	rep(i, 1, n)
		if(!vis[i])
			vec.pb(i);		
	
	copy();
	
	rep(i, 1, n - num)
		rep(j, 1, m)
			pic[j][i] = tmp[j][vec[i - 1]];
	n -= num;
}

void ir()
{
	int num;
	sfi(num);
	bool vis[MAX] = {0};
	rep(i, 1, num)
	{
		int r;
		sfi(r);
		vis[r] = true;
	}
	vector<int> vec;
	rep(i, 1, n)
		if(!vis[i])
			vec.pb(i);		
	
	copy();
	
	int cnt = 0;
	rep(i, 1, m)
	{
		if(vis[i])
		{
			cnt++;
			rep(j, 1, n)
				pic[cnt][j] = Node(0,0);
		}
		cnt++;
		rep(j, 1, n)
			pic[cnt][j] = tmp[i][j];
	}
	m += num;
}

void ic()
{
	int num;
	sfi(num);
	bool vis[MAX] = {0};
	rep(i, 1, num)
	{
		int c;
		sfi(c);
		vis[c] = true;
	}
	vector<int> vec;
	rep(i, 1, n)
		if(!vis[i])
			vec.pb(i);		
	
	copy();
	
	int cnt = 0;
	rep(i, 1, n)
	{
		if(vis[i])
		{
			cnt++;
			rep(j, 1, m)
				pic[j][cnt] = Node(0,0);
		}
		cnt++;
		rep(j, 1, m)
			pic[j][cnt] = tmp[j][i];
	}
	n += num;
}

void query(int x, int y)
{
	rep(i, 1, m)
	{
		rep(j, 1, n)
		{
			if(pic[i][j] == Node(x, y))
			{
				printf("Cell data in (%d,%d) moved to (%d,%d)\n", x, y, i, j);
				return;
			}
		}
	}
	printf("Cell data in (%d,%d) GONE\n", x, y);
}

void print()
{
	rep(i, 1, m)
	{
		rep(j, 1, n)
			printf("(%d,%d) ", pic[i][j].r, pic[i][j].c);
		putchar('\n');
	}
}

int main()
{
	int kase = 0;
	while(~scanf("%d%d", &m, &n))
	{
		if(!m && !n)
			break;
		
		if(checkblank)
			putchar('\n');
		printf("Spreadsheet #%d\n", ++kase);
		
		init();
		
		int times;
		sfi(times);
		while(times--)
		{
			char opr[MAX];
			sfs(opr);
			if(opr[0] == 'E')
				ex();
			else if(opr[0] == 'D' && opr[1] == 'R')
				dr();
			else if(opr[0] == 'D' && opr[1] == 'C')
				dc();
			else if(opr[0] == 'I' && opr[1] == 'C')
				ic();
			else
				ir();
		}
		int ques;
		sfi(ques);
		while(ques--)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			query(x, y);
		}
		checkblank = true;
	}
	return 0;
}