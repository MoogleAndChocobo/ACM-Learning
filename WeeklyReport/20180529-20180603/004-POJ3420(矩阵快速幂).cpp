#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <functional>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define sfd(a) scanf("%l", &a)
#define sfu(a) scanf("%llu", &a)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define pb(a) push_back(a)

const int MAX = 1e3 + 50;
const int N = 1e3;
const int MOD = 1e9 + 7;

LL mod;

struct Matrix
{
	int n, m;
	int a[10][10];
	
	Matrix(int n_, int m_)
	{
		n = n_;
		m = m_;
		mem(a);
	}
	
	friend Matrix operator *(Matrix a, Matrix b)
	{
		Matrix ans(a.n, a.m);
		rep(i, 0, ans.n) rep(j, 0, ans.m) rep(k, 0, ans.m)
			ans.a[i][j] = (ans.a[i][j] + a.a[i][k] * b.a[k][j]) % mod;
		return ans;
	}
	
	friend Matrix operator ^(Matrix b, LL a)
	{
		Matrix ans(4, 1);
		ans.a[0][0] = 1;
		ans.a[1][0] = 5;
		ans.a[2][0] = 11;
		ans.a[3][0] = 36;
		LL m = a;
		Matrix tmp(4, 4);
		tmp.a[0][1] = tmp.a[1][2] = tmp.a[2][3] = tmp.a[3][1] = tmp.a[3][3] = 1;
		tmp.a[3][0] = -1;
		tmp.a[3][2] = 5;
		while(m)
		{
			if(m&1)
				ans = tmp * ans;
			tmp = tmp * tmp;
			m>>=1;
		}
		return ans;
	}
};

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
	//~ freopen("out.txt", "r" , stdout);
#endif

	LL n;
	while(~scanf("%lld%lld", &n, &mod))
	{
		if(!n && !mod)
			break;
		
		LL ans = 0;
		if(mod == 1)
			ans = 0;
		else if(n == 1)
			ans = 1ll % mod;
		else if(n == 2)
			ans = 5ll % mod;
		else if(n == 3)
			ans = 11ll % mod;
		else if(n == 4)
			ans = 36ll % mod;
		else
		{
			Matrix mat(4, 4);
			mat.a[0][1] = mat.a[1][2] = mat.a[2][3] = mat.a[3][1] = mat.a[3][3] = 1;
			mat.a[3][0] = -1;
			mat.a[3][2] = 5;
			mat = mat ^ (n - 4);
			ans = mat.a[3][0];
		}
		while(ans < 0)
			ans += mod;
		printf("%lld\n", ans);
	}
	return 0;
}
