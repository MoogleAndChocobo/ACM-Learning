#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define sfl(a) scanf("%lld", &a)
#define sfi(a) scanf("%d", &a)

const int MAX = 1e4 + 5;
const int N = 9999;


ll eular(ll n)
{
	ll res = n, a = n;
	for (ll i = 2; i * i <= a; i++)
	{
		if (a % i == 0)
		{
			res -= res / i;
			while (a % i == 0)
				a /= i;
		}
	}
	if (a > 1)
		res -= res / a;
	return res;
}


const int L=2;
ll eu;
struct mat
{
	ll a[L][L];
	mat(bool b=0)
	{
		memset(a,0,sizeof(a));
		if(b)
		{
			for(int i=0;i<L;i++)
			{
				a[i][i]=1;
			}
		}
	}
	friend mat operator*(const mat &x ,const mat &y)
	{
		mat c(0);
		for(int i=0;i<L;i++)
		{
			for(int j=0;j<L;j++)
			{
				for(int k=0;k<L;k++)
				{
					c.a[i][j]=(c.a[i][j]+x.a[i][k]*y.a[k][j])%eu;
				}
				c.a[i][j]=c.a[i][j]+eu;
			}
		}
		return c;
	}
};


void f(ll x,ll & c ,ll & d)
{
	mat ans(1);
	mat a(0);
	a.a[0][0]=a.a[1][0]=a.a[0][1]=1;
	while (x)
	{
		if(x&1)ans=ans*a;
		a=a*a;
		x>>=1;
	}
	c=ans.a[0][1];
	d=ans.a[1][1];
}

ll Pow(ll a, ll b,ll MOD)
{
	ll ans =1;
	a%=MOD;
	while(b)
	{
		if(b&1)ans=(ans*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return ans;
}



int main()
{
	int t, cnt = 0;
	ll a,b,n,MOD;
	MOD=1e9+7;
	while(~scanf("%lld %lld %lld",&a,&b,&n)){
		ll c=0,d=0;
		eu = eular(MOD);
		f(n,c,d);
		ll ans=Pow(a,d,MOD)*Pow(b,c,MOD) % MOD;
		//printf("Case #%d: %lld\n",++cnt, ans);
		printf("%lld\n",ans);
	}
	return 0;
}