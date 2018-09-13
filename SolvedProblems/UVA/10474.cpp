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

const int MAX = 1e4 + 5;
const int L = 2;
const LL MOD = 10000;
const int dir[MAX][MAX] = {{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,1},{1,-1}};

int s[MAX];

int main()
{
	int kase = 0;
	int n, times;
	while(~scanf("%d%d", &n, &times))
	{
		if(!n && !times)
			break;
		printf("CASE# %d:\n", ++kase);
		rep(i, 1, n)
			sfi(s[i]);
		sort(s + 1, s + n + 1);
		while(times--)
		{
			int num;
			sfi(num);
			int idx = lower_bound(s + 1, s + n + 1, num) - s;
			if(idx <= n && s[idx] == num)
				printf("%d found at %d\n", num, idx);
			else
				printf("%d not found\n", num);
		}
	}
	return 0;
}