//#include <bits/stdc++.h>
#include<cstdio>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)

const int MAX = 1e5 + 10;
const LL MOD = 1e9 + 7;

int eular(int x)
{
	int ans=x;
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			ans-=ans/i;
			while(x%i==0)
				x/=i;
		}
	}
	if(x!=1)ans-=ans/x;
	return ans;
}

int main()
{
	int n;
	while(~scanf("%d",&n)&&n)
	{
		printf("%d\n",eular(n));
	}
	return 0;
}