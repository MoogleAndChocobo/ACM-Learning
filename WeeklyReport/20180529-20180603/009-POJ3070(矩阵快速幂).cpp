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

const int MAX = 10 + 5;
const int L = 2;
const LL MOD = 10000;

LL a, b;

struct Matrix
{
	int n, m;
	LL p[MAX][MAX];
	
	Matrix(int n_, int m_)
	{
		n = n_;
		m = m_;
		mem(p);
	}
	
	friend Matrix operator *(Matrix a, Matrix b)
	{
		Matrix ans(a.n, a.m);
		rep(i, 0, ans.n - 1) rep(j, 0, ans.m - 1) rep(k, 0, ans.m - 1)
			ans.p[i][j] = (ans.p[i][j] + a.p[i][k] * b.p[k][j]) % MOD;
		return ans;
	}

	LL fpow(LL k)
	{
		Matrix ans(L, 1);
		ans.p[0][0] = ans.p[1][0] = 1;
		Matrix tmp(L, L);
		tmp.p[0][1] = 1;
		tmp.p[1][0] = 1;
		tmp.p[1][1] = 1;
		while(k)
		{
			if(k&1)
				ans = tmp * ans;
			tmp = tmp * tmp;
			k>>=1;
		}
		return ans.p[L - 1][0];
	}
};

int main()
{
	LL n;
	while(~sfl(n))
	{
		if(n == -1)
			break;
		
		Matrix mat(2, 2);
		LL ans = 0;
		if(n == 0)
			ans = 0;
		else if(n == 1)
			ans = a % MOD;
		else if(n == 2)
			ans = b % MOD;
		else
			ans = mat.fpow(n - 2);
		printf("%lld\n", ans);
	}
	return 0;
}
