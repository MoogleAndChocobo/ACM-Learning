#include<cstdio>
#include<cstring>
#include<iostream>
#include<set>

using namespace std;

const int MAX = 1e3 + 10;

#define sfs(a) scanf("%s", a)
#define rep(i, a, b) for(int i = a; i <= b; i++)

int main()
{

	char s[MAX];
	while(~sfs(s))
	{
		string tmp;
		set<string> st;
		st.insert(tmp);
		int len = strlen(s);
		s[len] = '_';
		rep(i, 0, len)
		{
			if(isalpha(s[i]))
				tmp += s[i];
			else
			{
				if(st.find(tmp) == st.end())
				{
					cout << tmp << endl;
					st.insert(tmp);
				}
				tmp.clear();
			}
		}
	}
	return 0;
}