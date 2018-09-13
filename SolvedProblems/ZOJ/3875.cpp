#include<bits/stdc++.h>
using namespace std;
struct node
{
	char s[77];
	int n;
	bool operator<(const node & x)const
	{
		return n<x.n;
	}
}S[105],M[105],D[105];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int s,m,d;
		scanf("%d %d %d",&s,&m,&d);
		for(int i=0;i<s;i++)
		{
            scanf("%s %d",S[i].s,&S[i].n);
		}
		sort(S,S+s);
		for(int i=0;i<m;i++)
		{
            scanf("%s %d",M[i].s,&M[i].n);
		}
		sort(M,M+m);
		for(int i=0;i<d;i++)
		{
            scanf("%s %d",D[i].s,&D[i].n);
		}
		sort(D,D+d);

        printf("%d %s %s %s\n",S[s/2].n+M[m/2].n+D[d/2].n,S[s/2].s,M[m/2].s,D[d/2].s);
	}
}