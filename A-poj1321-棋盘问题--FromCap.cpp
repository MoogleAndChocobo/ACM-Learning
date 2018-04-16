#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct node
{
	int x,y,z;
	int w;
};
int tur[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
char map[40][40][40];
bool vis[40][40][40];
int L,R,C;
int bfs(node s)
{
	queue<node> q;
	q.push(s);
	memset(vis,0,sizeof(vis));
	vis[s.x][s.y][s.z]=true;
	while(!q.empty())
	{
		node p=q.front();
		q.pop();
		if(map[p.x][p.y][p.z]=='E')return p.w;
		for(int i=0;i<6;i++)
		{
			node pp=p;
			pp.x+=tur[i][0];
			pp.y+=tur[i][1];
			pp.z+=tur[i][2];
			if(pp.x<0||pp.y<0||pp.z<0||pp.x>=L||pp.y>=R||pp.z>=C||map[pp.x][pp.y][pp.z]=='#'||vis[pp.x][pp.y][pp.z])continue;
			vis[pp.x][pp.y][pp.z]=true;
			pp.w++;
			q.push(pp);
		}
	}
	return -1;
}
int main()
{
	while(scanf("%d%d%d",&L,&R,&C)==3&&L&&R&&C)
	{
		node p;
		for(int i=0;i<L;i++)
			for(int j=0;j<R;j++)
			{
				scanf("%s",map[i][j]);
				for(int k=0;k<C;k++)
					if(map[i][j][k]=='S')
					{
						p.x=i;
						p.y=j;
						p.z=k;
						p.w=0;
					}
			}
		int ans=bfs(p);
		if(ans==-1)printf("Trapped!\n");
		else printf("Escaped in %d minute(s).\n",ans);
	}
}
