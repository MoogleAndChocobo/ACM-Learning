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
const LL MOD = 9973;

struct Matrix
{
	int n;
	LL p[MAX][MAX];
	
	Matrix(int nn)
	{
		n = nn;
		mem(p);
	}
	
	friend Matrix operator *(Matrix a, Matrix b)
	{
		Matrix ans(a.n);
		rep(i, 0, ans.n - 1) rep(j, 0, ans.n - 1) rep(k, 0, ans.n - 1)
			ans.p[i][j] = (ans.p[i][j] + a.p[i][k] * b.p[k][j]) % MOD;
		return ans;
	}
	
	friend Matrix operator ^(Matrix a, LL k)
	{
		Matrix ans(a.n), tmp(a.n);
		rep(i, 0, a.n - 1) rep(j, 0, a.n - 1)
			ans.p[i][j] = tmp.p[i][j] = a.p[i][j];
		--k;
		while(k)
		{
			if(k&1)
				ans = tmp * ans;
			tmp = tmp * tmp;
			k>>=1;
		}
		return ans;
	}
	
	void show()
	{
		putchar('\n');
		rep(i, 0, n - 1)
		{
			rep(j, 0, n - 1)
				printf("%lld ", p[i][j]);
			putchar('\n');
		}
		putchar('\n');
	}
};

int main()
{
	int kase;
	sfi(kase);
	while(kase--)
	{
		int n;
		LL k;
		scanf("%d%lld", &n, &k);
		Matrix mat(n);
		rep(i, 0, n - 1) rep(j, 0, n - 1)
			sfl(mat.p[i][j]);
		Matrix ans = mat ^ k;
		LL res = 0;
		rep(i, 0, n - 1)
			res = (res + ans.p[i][i]) % MOD;
		printf("%lld\n", res);
	}
	return 0;
}