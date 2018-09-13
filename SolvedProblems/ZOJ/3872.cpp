#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll first[1000005];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(first,0,sizeof(first));
		ll n,a;
		scanf("%lld",&n);
		ll dp=0,ans=0;
        for(ll i=0;i<n;i++)
		{
			scanf("%lld",&a);
			dp=dp+(i-first[a]+1)*a;
			first[a]=i+1;
			ans+=dp;
		}
        printf("%lld\n",ans);
	}
}