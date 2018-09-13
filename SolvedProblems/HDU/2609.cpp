#include <bits/stdc++.h>
using namespace std;
char t[111];
int main()
{
	for(int i=0;i<108;i++)t[i]='1';
	int n;
	while(cin>>n)
	{
		string s;
		set<string>st;
		for(int i=0;i<n;i++)
		{
			cin>>s;
			string d(t);
			const int len=s.size();
			for(int j=0;j<len;j++)
			{
				d=d<s?d:s;
				char c=s[0];
				s.erase(0,1);
				s=s+c;
			}
			st.insert(d);
		}
		printf("%d\n",st.size());
	}
}