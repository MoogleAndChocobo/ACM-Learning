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

const int MAX = 100000 + 50;
const int N = 100000;

LL a[MAX];
LL pre[MAX];
LL after[MAX];

int main()
{
	int n;
	LL m;
	scanf("%d%lld", &n, &m);
	rep(i, 1, n)
		sfl(a[i]);
	a[++n] = m;
	
	LL sum = 0;
	rep(i, 0, n)
	{
		if(i % 2)
			sum += a[i] - a[i - 1];
		pre[i] = sum;
	}
	
	LL tmp = 0;
	dow(i, n, 0)
	{
		if(i % 2 && i + 1 <= n)
			tmp += a[i + 1] - a[i];
		after[i] = tmp;
	}
	
	//~ rep(i, 0, n)
	//~ {
		//~ printf("%lld %lld\n", pre[i], after[i]);
	//~ }
	
	
	rep(i, 0, n - 1)
	{
		if(a[i + 1] - a[i] == 1)
			continue;
		int now = i % 2 ? a[i] + 1 : a[i + 1] - 1;
		LL tmp = 0;
		if(i % 2)
		{
			tmp = a[i + 1] - now;
			tmp += pre[i];
			tmp += after[i + 2];
		}
		else
		{
			tmp = now - a[i];
			tmp += i - 1 >= 0 ? pre[i - 1] : 0;
			tmp += after[i + 1];
		}
		sum = max(sum, tmp);
		//~ printf("tmp = %lld\n", tmp);
	}
	printf("%lld\n", sum);
	
	
	return 0;
}
