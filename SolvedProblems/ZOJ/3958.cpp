#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int f1=0,f2=0;
		int n;
		scanf("%d",&n);
		while(n--)
		{
            int k;
            scanf("%d",&k);
            switch(k)
            {
            	case 1:f1++;break;
            	case 2:f2++;break;
            	default:break;
            }
		}
		if(f1==f2)puts("Draw");
		else puts(f1>f2?"Kobayashi":"Tohru");
	}
}