#include<cstdio>
#include<stack>
#include<cctype>
#include<sstream>

using namespace std;

const int MAX = 10;

stack<int> stk;

int main()
{
	char s[MAX];
	while(~scanf("%s", s))
	{
		if(isdigit(s[0]))
		{
			stringstream ss(s);
			int tmpnum;
			ss >> tmpnum;
			stk.push(tmpnum);
		}
		else if(s[0] == '-')
		{
			int a = stk.top();
			stk.pop();
			int b = stk.top();
			stk.pop();
			stk.push(b - a);
		}
		else if(s[0] == '+')
		{
			int a = stk.top();
			stk.pop();
			int b = stk.top();
			stk.pop();
			stk.push(b + a);
		}
		else if(s[0] == '*')
		{
			int a = stk.top();
			stk.pop();
			int b = stk.top();
			stk.pop();
			stk.push(b * a);
		}
	}
	printf("%d\n", stk.top());
	return 0;
}