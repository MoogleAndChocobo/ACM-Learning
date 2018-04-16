#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cctype>
#include <queue>
#include <set>
#include <map>
#include <iostream>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LF;

#define fli freopen("in.txt", "r", stdin);
#define flo freopen("out.txt", "w", stdout);
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define	rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfs(a) scanf("%s", a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define pb(a) push_back(a)
#define all(c) (c).begin(),(c).end()
#define YES puts("YES")
#define NO puts("NO")
#define yes puts("yes")
#define no puts("no")
#define Yes puts("Yes")
#define No pus("No")

const int MAX = 30 + 10;
const int N = 16000;
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1007;
const double EPS = (double)1e-10;
const int LMON[15] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
const int CMON[15] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
const int dirnd[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
const int dirrd[6][3] = {{0,0,1},{0,0,-1},{1,0,0},{-1,0,0},{0,1,0},{0,-1,0}};

bool pic[MAX][MAX][MAX];
int vis[MAX][MAX][MAX];
int m, n, p, sx, sy, sz, ex, ey, ez;

struct Node
{
	int x, y, z;
	Node(int xx = 0, int yy = 0, int zz = 0):x(xx), y(yy), z(zz){}
};

void init()
{
	mem(pic), mem(vis);
}

bool check(int x, int y, int z)
{
	if(!vis[x][y][z] && pic[x][y][z] == 1)
		return true;
	return false;
}

int Bfs()
{
	queue<Node> q;
	q.push(Node(sx, sy, sz));
	while(!q.empty())
	{
		Node cur = q.front();
		q.pop();
		if(cur.x == ex && cur.y == ey && cur.z == ez)
			return vis[ex][ey][ez];
		rep(i, 0, 5)
		{
			Node now = cur;
			now.x += dirrd[i][0];
			now.y += dirrd[i][1];
			now.z += dirrd[i][2];
			if(check(now.x, now.y, now.z))
			{
				q.push(now);
				vis[now.x][now.y][now.z] = vis[cur.x][cur.y][cur.z] + 1;
			}
		}
	}
	return -1;
}

int main()
{
#ifdef LOCAL
	//~ fli
	//~ flo
#endif	//LOCAL

	sync
	
	while(cin >> m >> n >> p)
	{
		if(!m && !n && !p)
			break;
			
		init();
		rep(i, 1, m) rep(j, 1, n) rep(k, 1, p)
		{
			char c;
			cin >> c;
			if(c == 'E')
				pic[i][j][k] = 1, ex = i, ey = j, ez = k;
			else if(c == 'S')
				sx = i, sy = j, sz = k;
			else if(c == '.')
				pic[i][j][k] = 1;
		}
		
		int ans = Bfs();
		if(ans == -1)
			cout << "Trapped!" << endl;
		else
			cout << "Escaped in " << ans << " minute(s)." << endl;
	}
	return 0;
}
