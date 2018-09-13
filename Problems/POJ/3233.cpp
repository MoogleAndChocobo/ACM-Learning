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

const int MAX = 1e2 + 5;
const int L = 2;
const LL MOD = 10000;

LL mod;
int n;

struct Matrix
{
	LL p[MAX][MAX];
	
	Matrix()
	{
		mem(p);
	}
	
	friend Matrix operator *(Matrix a, Matrix b)
	{
		Matrix ans;
		rep(i, 0, n - 1) rep(j, 0, n - 1) rep(k, 0, n - 1)
			ans.p[i][j] = (ans.p[i][j] + a.p[i][k] * b.p[k][j] % mod) % mod;
		return ans;
	}
	
	friend Matrix operator +(Matrix a, Matrix b)
	{
		Matrix ans;
		rep(i, 0, n - 1) rep(j, 0, n - 1)
			ans.p[i][j] = (a.p[i][j] + b.p[i][j]) % mod;
		return ans;
	}
};

struct Node
{
	Matrix a, b;
	
	friend Node operator *(Node a, Node b)
	{
		Node ans;
		ans.a = a.a * b.a;
		ans.b = a.a * b.b + a.b;
		//~ ans.c = a.c * b.a + a.d * b.c;
		//~ ans.d = a.c * b.b + a.d * b.d;
		return ans;
	}
	
	friend Matrix operator ^(Node a, LL k)
	{
		Node tmp = a;
		--k;
		while(k)
		{
			if(k&1)
				a = a * tmp;
			tmp = tmp * tmp;
			k>>=1;
		}
		return a.b;
	}
};

int main()
{
	LL k;
	scanf("%d%lld%lld", &n, &k, &mod);
	Matrix now;
	rep(i, 0, n - 1) rep(j, 0, n - 1)
		sfl(now.p[i][j]), now.p[i][j] %= mod;
	Node cons;
	cons.a = cons.b = now;
	Matrix ans = cons ^ k;
	rep(i, 0, n - 1)
	{
		rep(j, 0, n - 1)
		{
			printf("%lld", ans.p[i][j]);
			putchar(j != n - 1 ? ' ' : '\n');
		}
	}
	return 0;
}