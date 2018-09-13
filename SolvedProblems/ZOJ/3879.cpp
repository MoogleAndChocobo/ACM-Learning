#include<cstdio>
#include<cctype>
#include<map>
#include<set>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
inline int in()
{
	char c=getchar();
	while(!isdigit(c))c=getchar();
	int x=0;
	while(isdigit(c))
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
typedef set< pair<int,int> >sii;
typedef map<int,sii>mmp;

struct node
{
	double a;
	int pos;
	bool operator<(const node & x)const
	{
		return a>x.a;
	}
}a[105];

bool cmp(const node & x,const node &y)
{
	return x.pos<y.pos;
}
const double eps=1e-5;

int main()
{
	int T=in();
	while(T--)
	{
		int n=in(),q=in();
		double s=(double)(in());
		int c=in();
		for(int i=1;i<=n;i++)
		{
			a[i].a=s;
			a[i].pos=i;
		}
		for(int i=0;i<c;i++)
		{
			mmp mis;
			int batt[12][105]={0};
			int p=in();
			for(int j=0;j<p;j++)
			{
				int A=in(),B=in(),C=in();
				if(mis[A].find(make_pair(C,B))==mis[A].end())
				{
					batt[C][B]++;
					mis[A].insert(make_pair(C,B));
				}
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=q;j++)
				{
					if(batt[j][i])a[i].a-=(double)(n-1);
				}
				for(sii::iterator j=mis[i].begin();j!=mis[i].end();j++)
				{
					a[i].a=a[i].a+(double)(n-1)/(double)batt[j->first][j->second];
				}
			}
			for(int i=1;i<=q;i++)
			{
				int cnt=0;
				bool z[105]={0};
				for(int j=1;j<=n;j++)
				{
					z[j]=in();
					if(!z[j]){
						a[j].a-=(double)(n-1);
						cnt++;
					}
				}
				for(int j=1;j<=n;j++)
				{
					if(z[j])
					{
						a[j].a+=(double)(n-1)*(double)(cnt)/(n-cnt);
					}
				}
			}

			sort(a+1,a+n+1);

			int u=in();
			for(int i=0;i<u;i++)
			{
				int m=in();
				for(int j=1;j<=n;j++)
				{
					int k=j;
					while(fabs(a[k].a-a[k-1].a)<=eps&&k>=2)k--;
					if(a[j].pos==m)
					{
						printf("%.8lf %d\n",a[j].a,k);
					}
				}
			}

			sort(a+1,a+n+1,cmp);
		}


	}
}