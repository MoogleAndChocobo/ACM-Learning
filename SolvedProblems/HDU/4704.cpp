#include<bits/stdc++.h>
using namespace std;
char s[100005];
typedef long long ll;
const int MOD=1e9+7;
ll Pow(ll x,ll y)
{
	ll ans=1;
	while(y)
	{
		if(y&1)ans=(ans*x)%MOD;
		x=(x*x)%MOD;
		y>>=1;
	}
	return ans;
}
int main()
{
	while(~scanf("%s",s))
	{
		ll b=0;
		const int len=strlen(s);
		for(int i=0;i<len;i++){
			b=b*10+s[i]-'0';
			b=b%(MOD-1);
		}
		printf("%lld\n",Pow(2,b-1));
	}
}