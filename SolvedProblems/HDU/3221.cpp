#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll in()
{
	char c=getchar();
	while(!isdigit(c))c=getchar();
	ll x=0;
	while(isdigit(c))
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
ll eular(ll a)
{
	ll res = a;
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

ll fib[10000];
void f(ll x,ll & c,ll & d)
{
	fib[0] = 1;
    fib[1] = 1;
    int i;
    for(i = 2; i <= x; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
        if(fib[i] >= eu)
            break;
    }
    if(i>x)
	{
		c=fib[x];
		d=fib[x-1];
		return;
	}
	mat ans(1);
	mat a(0);
	a.a[0][0]=a.a[1][0]=a.a[0][1]=1;
	while (x)
	{
		if(x&1)ans=ans*a;
		a=a*a;
		x>>=1;
	}
	c=ans.a[0][0];
	d=ans.a[0][1];
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
	int t;
	ll a,b,n,MOD;
	scanf("%d", &t);
	for(int k=1;k<=t;k++)
	{
		scanf("%lld %lld %lld %lld",&a,&b,&MOD,&n);
		ll c=0,d=0;
		if(n==1)
		{
			printf("Case #%d: %lld\n",k, a%MOD);
			continue;
		}
		if(n==2)
		{
			printf("Case #%d: %lld\n",k, b%MOD);
			continue;
		}
		if(n==3)
		{
			printf("Case #%d: %lld\n",k, a*b%MOD);
			continue;
		}
		if(MOD==1)
		{
			printf("Case #%d: 0\n",k);
			continue;
		}
		eu = eular(MOD);
		f(n-2,c,d);
		ll ans=Pow(a,d,MOD)*Pow(b,c,MOD) % MOD;
		printf("Case #%d: %lld\n",k, ans);
	}
	return 0;
}