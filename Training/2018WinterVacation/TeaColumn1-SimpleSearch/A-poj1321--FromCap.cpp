#include<cstdio>
#include<cstring>
char map[10][10];
int n;
int dfs(int line,int move)
{
	if(move==0)return 1;
	if(line+move>n)return 0;
	int ans=dfs(line+1,move);
	for(int i=0;i<n;i++)
	{
		if(map[line][i]=='#')
		{
			bool flag=false;
			for(int j=0;(!flag)&&j<n;j++)
				if(map[j][i]=='*')
					flag=true;
			if(flag)continue;
			map[line][i]='*';
			ans+=dfs(line+1,move-1);
			map[line][i]='#';
		}
	}
	return ans;
}
int main()
{
	int k;
	while(scanf("%d%d",&n,&k)==2&&(n+1)&&(k+1))
	{
		for(int i=0;i<n;i++)
			scanf("%s",map[i]);
		printf("%d\n",dfs(0,k));
	}
}
