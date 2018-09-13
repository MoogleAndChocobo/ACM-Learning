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
const int N = 1500;
const LL MOD = 10000;
const int dir[MAX][MAX] = {{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,1},{1,-1}};

priority_queue<LL, vector<LL>, greater<LL> > pq;
set<LL> s;

int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif

	
	pq.push(1L);
	int cnt = 0;
	s.insert(1L);
	
	LL cur;
	while(true)
	{
		cur = pq.top();
		pq.pop();
		if(++cnt == N)
			break;
		
		LL now = cur * 2;
		if(s.find(now) == s.end())
			pq.push(now), s.insert(now);
		
		now = cur * 3;
		if(s.find(now) == s.end())
			pq.push(now), s.insert(now);
			
		now = cur * 5;
		if(s.find(now) == s.end())
			pq.push(now), s.insert(now);
	}
	printf("The 1500'th ugly number is %lld.\n", cur);
	return 0;
}