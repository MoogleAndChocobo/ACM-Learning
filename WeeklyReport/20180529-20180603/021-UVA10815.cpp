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

set<string> st;

int main()
{	
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
#endif

	sync

	string s;
	while(cin >> s)
	{
		int len = s.size();
		rep(i, 0, len - 1)
		{
			if(!isalpha(s[i]))
				s[i] = ' ';
			else if(isupper(s[i]))
				s[i] = tolower(s[i]);
		}
		stringstream ss(s);
		string now;
		while(ss >> now)
		{
			st.insert(now);
		}
	}
	for(set<string>::iterator it = st.begin(); it != st.end(); ++it)
		cout << *it << "\n";
	return 0;
}
