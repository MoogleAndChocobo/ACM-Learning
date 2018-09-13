#include<algorithm>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdio>
using namespace std;
char s[111];
int a[12];
int main()
{
	int T;
	scanf("%d",&T);
	gets(s);
	while(T--)
	{
		int n=0;
		gets(s);
		const int len=strlen(s);
		for(int i=0;i<len;i++)
		{
			if(isdigit(s[i]))
			{
				a[n++]=s[i]-'0';
			}
		}
		if(n==2&&a[0]==0)
		{
			printf("%d\n",a[1]);
			continue;
		}
		int ans=0x3f3f3f3f;
        do
		{
			int x=0,y=0;
			for(int i=0;i<n/2;i++)
			{
				if(x==0&&a[i]==0)goto N;
				x=x*10+a[i];
			}
			for(int i=n/2;i<n;i++)
			{
				if(y==0&&a[i]==0)goto N;
				y=y*10+a[i];
			}
			ans=min(ans,abs(x-y));
			N:;
		}while(next_permutation(a,a+n));
		printf("%d\n",ans);
	}
}