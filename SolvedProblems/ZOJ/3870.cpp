#include<bits/stdc++.h>
using namespace std;
int v[35];
int a[100005];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(v,0,sizeof(v));
		int n,b;
		long long ans=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		random_shuffle(a,a+n);
		sort(a,a+n);
		for(int i=0;i<n;i++)
		{
			int b=a[i];
			int cnt=1;
			while(b)
			{
				if(~b&1)ans+=v[cnt];
				b>>=1;
				cnt++;
			}
			v[cnt-1]++;
		}
		printf("%lld\n",ans);
	}
}