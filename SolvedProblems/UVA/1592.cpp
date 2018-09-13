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
#define endl "\n"
#define all(a) a.begin(),a.end()
#define fr first
#define sc second

const int MAX = 1e4 + 5;
const int L = 2;
const int N = 1500;
const LL MOD = 10000;
const int dir[MAX][MAX] = {{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,1},{1,-1}};
const int multiply = 1000000;

int n, m;
char tmp[MAX];
string s[10050][15];
int pic[10050][15];
map<string,int> mp;
map<LL,int> check[200];

void init()
{
	int cnt = 0;
	rep(i, 1, n)
	{
		rep(j, 1, m)
		{
			int now = mp[s[i][j]];
			if(mp[s[i][j]] != 0)
				pic[i][j] = now;
			else
			{
				pic[i][j] = ++cnt;
				mp[s[i][j]] = cnt;
			}
		}
	}
}


int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif

	while(~scanf("%d%d", &n, &m))
	{
		getchar();
		mp.clear();
		rep(i, 1, 199)
			check[i].clear();
		rep(i, 1, n)
		{
			fgets(tmp, 1000, stdin);
			int len = strlen(tmp);
			rep(j, 0, len - 1)
			{
				if(tmp[j] == ' ')
					tmp[j] = '-';
				else if(tmp[j] == ',')
					tmp[j] = ' ';
			}

			char now[100];
			rep(j, 1, m)
			{
				sscanf(tmp, "%s", now);	
				s[i][j] = now;
				bool f = false;
				rep(k, 0, len - 1)
				{
					if(tmp[k] != ' ')
						tmp[k] = ' ', f = true;
					else if(f)
						break;
				}
			}
		}
		
		init();
		
		bool flag = false;
		rep(i, 1, n)
		{
			rep(j, 1, m)
			{
				rep(k, 1, m)
				{
					if(j == k)
						continue;
					int now = j * 10 + k;
					LL str = pic[i][j] * 1000000 + pic[i][k];
					int gt = check[now][str];
					if(gt != 0 && gt != i)
					{
						puts("NO");
						printf("%d %d\n%d %d\n", gt, i, j, k);
						flag = true;
						goto a;
					}
					else
						check[now][str] = i;
				}
			}
		}
		a:;
		
		if(!flag)
			puts("YES");
	}
	return 0;
}