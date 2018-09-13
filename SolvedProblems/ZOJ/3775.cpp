#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define rep(i, a, b) for(int i = a; i <= b; i++)

int main()
{
	string M;
	int n;
	cin>>n;
	getline (cin,M);
	const string cmp="Hello, world!";
	for(int i=0;i<n;i++)
	{
		string s;
		string ans;
		getline(cin,s);
		const int len = s.size();
		for(int i=0;i<len;i++)
		{
			if(s[i]=='_')ans+=s;
			else if(s[i]=='!')ans+=cmp;
		}
		if(ans==s)puts("Yes");
		else puts("No");
	}
	return 0;
}