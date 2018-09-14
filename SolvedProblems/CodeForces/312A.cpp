#include<iostream>
#include<string>
#include<cstdio>

using namespace std;

int main()
{
	int n;
	while(cin >> n)
	{
		getchar();
		while(n--)
		{
			string s;
			getline(cin, s);
			bool flag, judge;
			int a = s.size();
			int b = s.find("miao.");
			if(s[a - 1] == '.' && s[a - 2] == 'a' && s[a - 3] == 'l' && s[a - 4] == 'a' && s[a - 5] == 'l')
				flag = true;
			else
				flag = false;
			if(b == 0)
				judge = true;
			else
				judge = false;

			if(flag && !judge)
				printf("Freda's\n");
			else if(!flag && judge)
				printf("Rainbow's\n");
			else
				printf("OMG>.< I don't know!\n");
		}
	}
	return 0;
}