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

const int MAX = 1e2 + 5;
const int L = 2;
const int N = 1500;
const LL MOD = 10000;
const int dir[MAX][MAX] = {{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,1},{1,-1}};

string ans[105][105];

int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif

	sync
	
	int n;
	while(cin >> n)
	{
		rep(i, 0, 104) rep(j, 0, 104)
			ans[i][j] = "";
		
		rep(i, 1, 60)
			cout << "-";
		cout << endl;
		
		vector<string> vec;
		rep(i, 1, n)
		{
			string tmp;
			cin >> tmp;
			vec.pb(tmp);
		}
		sort(all(vec));
		
		int mx = 0;
		rep(i, 0, n - 1)
			mx = max(mx, (int)vec[i].size());
		if(mx > 60)
			mx = 60;
		int ncnt = 62 / (mx + 2);
		int num = n / ncnt;
		if(n % ncnt)
			num++;
		
		rep(i, 0, n - 1)
		{
			int len = vec[i].size();
			rep(j, len + 1, mx)
				vec[i] += " ";
			ans[(i % num) + 1][(i / num) + 1] = vec[i];
		}
	
		int cnt = 0;
		rep(i, 1, num)
		{
			rep(j, 1, ncnt)
			{
				if(ans[i][j] == "")
					break;
				if(j != 1)
					cout << "  ";
				cnt++;
				cout << ans[i][j];
				if(cnt >= n)
					goto a;
			}
			cout << endl;
		}
		a:;
		//~ if(num * ncnt != n)
		cout << endl;
		
	}
	return 0;
}
