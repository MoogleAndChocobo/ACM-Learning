#include<cstdio>
using namespace std;
typedef long long ll;
ll gcd(ll x,ll y)
{
	return y==0?x:gcd(y,x%y);
}
ll mul(ll a, ll b, ll m)
{
	return (a * b - ll(a / (long double)m * b + 1e-3) * m + m) % m;
}
ll euler(ll x)
{
	ll ans=x;
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			ans-=ans/i;
			while(x%i==0)x/=i;
		}
	}
	if(x!=1)ans-=ans/x;
	return ans;
}

bool pow(ll b,ll p)
{
	ll ans=1,a=10;
	while(b)
	{
		if(b&1)ans=mul(ans,a,p);
		a=mul(a,a,p);
		b>>=1;
	}
	return ans==1?true:false;
}

int main()
{
	ll l;
	int cnt=1;
	while(~scanf("%lld",&l)&&l)
	{
		printf("Case %d: ",cnt++);
		ll p=9*l/gcd(8,l);
        if(gcd(10,p)==1)
		{
			ll k=euler(p),ans=k;
			for(ll i=1;i*i<=k;i++)
			{
                if(k%i==0)
				{
					if(pow(i,p))ans=ans<i?ans:i;
					if(pow(k/i,p))ans=ans<k/i?ans:k/i;
				}
			}
			printf("%lld\n",ans);
		}
		else printf("0\n");
		N:;
	}
	return 0;
}