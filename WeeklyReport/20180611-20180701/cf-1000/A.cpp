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
#include <cmath>
 
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
 
const int MAXN = 1000 + 5;
const double EPS = 1e-6;
const double PI = acos(-1.0);

const LL MOD = 1000 + 50;

const int MAX = 1000 + 50;
const int N = 1000;

map<string,int> mp;
vector<string> a;
vector<string> b;

int main()
{
	sync
	
	int n;
	cin >> n;
	rep(i, 1, n)
	{
		string tmp;
		cin >> tmp;
		mp[tmp]++;
	}
	int ans = 0;
	rep(i, 1, n)
	{
		string tmp;
		cin >> tmp;
		if(mp[tmp])
			mp[tmp]--;	
		else
			ans++;
	}
	printf("%d\n", ans);
	
	
	return 0;
}
