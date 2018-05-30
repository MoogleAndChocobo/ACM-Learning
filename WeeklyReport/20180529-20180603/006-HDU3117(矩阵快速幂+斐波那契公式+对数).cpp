#include <bits/stdc++.h>

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

LL rec[MAX];

void init()
{
	rec[0] = 0;
	rec[1] = 1;
	rep(i, 2, 39)
		rec[i] = rec[i - 1] + rec[i - 2];
}


LL solve(LL n)
{
	double t = n*log10((1+sqrt(5.))/2.)-log10(sqrt(5.));
	t -= LL(t);
	t = pow(10, t);
	while(t < 1000.)
		t *= 10.;
	return LL(t);
}

struct Matrix
{
	int n, m;
	LL p[10][10];
	
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
	
	LL solve(LL k)
	{
		Matrix ans(2, 1);
		ans.p[0][0] = 1;
		ans.p[1][0] = 1;
		
		
		Matrix tmp(2, 2);
		tmp.p[0][1] = tmp.p[1][0] = tmp.p[1][1] = 1;
		
		while(k)
		{
			if(k&1)
				ans = tmp * ans;
			tmp = tmp * tmp;
			k>>=1;
		}
		return ans.p[1][0];
	}
};


int main()
{
	init();
	
	LL n;
	while(~scanf("%lld", &n))
	{
		if(n <= 39LL)
			printf("%lld\n", rec[n]);
		else
		{
			Matrix mat(L, L);
			printf("%lld...%04lld\n", solve(n), mat.solve(n - 2));
		}
	}
	return 0;
}
