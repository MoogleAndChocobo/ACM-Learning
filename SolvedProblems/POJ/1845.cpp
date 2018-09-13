#include <stdio.h>
#include <math.h>
using namespace std;
typedef long long ll;


ll mul(ll a, ll b, ll m)
{
	return (a * b - ll(a / (long double)m * b + 1e-3) * m + m) % m;
}

ll fpow(ll a, ll b,ll p)
{
	ll base = 1;
	a %= p;
	while (b)
	{
		if (b & 1)
			base = mul(a,base,p);
		a = mul(a,a,p);
		b >>= 1;
	}
	return base;
}



const int MOD=9901;
int main()
{
	 ll a,b;
	 while(~scanf("%lld %lld",&a,&b))
	 {
		if(b==0)
		{
			printf("1\n");
			continue;
		}
		if(a==1)
		{
			printf("1\n");
			continue;
		}
		ll ans=1;
		for(int i=2;i*i<=a;i++)
		{
			if(a%i==0)
			{
				ll k=0;
				while(a%i==0)
				{
					a/=i;
					k+=b;
				}
				ll m=MOD*(i-1);
				ll n=fpow(i,k+1,m)+m-1;
				n=(n/(i-1))%MOD;
				ans =(ans*n)%MOD;
			}
		}
		if(a>1)
		{
			ll m=MOD*(a-1);
			ll n=fpow(a,b+1,m)+m-1;
			n=(n/(a-1))%MOD;
			ans =(ans*n)%MOD;
		}
		printf("%lld\n",ans);
	}
	return 0;
}