#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	string name;
	scanf("%d",&T);
    while(T--)
	{
		int n,q,k,m;
		cin>>n>>q>>k;
        map<string,int>mp;
        for(int i=0;i<k;i++)
		{
			cin>>name;
			mp[name]=0;
		}
        for(int i=0;i<q;i++)
		{
			cin>>m;
			for(int j=0;j<m;j++)
			{
				cin>>name;
				mp[name]|=(1<<(q-i-1));
			}
			//printf("%d\n",mp);
		}
		for(int i=0;i<n;i++)
		{
			int kk=0,ff;
			for(int j=0;j<q;j++)
			{
				scanf("%d",&ff);
				kk=kk*2+ff;
			}

			string name;
			for(map<string,int>::iterator i=mp.begin();i!=mp.end();i++)
			{
				if(i->second==kk)
				{
					if(name.empty())name=i->first;
					else {
						puts("Let's go to the library!!");
						goto N;
					}
				}
			}
			if(name.empty())puts("Let's go to the library!!");
			else printf("%s\n",name.data());
			N:;
		}


	}
}