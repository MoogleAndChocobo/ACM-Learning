#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
	{
		memset(a,0,sizeof(a));
		int n,c;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&c);
			a[c]++;
		}
		int m=0,num=0,nn=0;
		for(int i=1;i<=1000;i++)
		{
			if(a[i]==m)num++;
			if(a[i]>m)
			{
				m=a[i];
				nn=i;
				num=1;
			}
		}
		if(num==1)printf("%d\n",nn);
		else printf("Nobody\n");
	}
}