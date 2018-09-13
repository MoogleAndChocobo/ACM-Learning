#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define mem(a) memset(a, 0, sizeof(a))
#define sfi(a) scanf("%d", &a)


const int MAX = 1e3 + 5; 

int s[MAX];
int ans, cnt, aim, n;
bool flag;

void init()
{
	mem(s);
	cnt = ans = 0;
	flag = false;
}

bool solve(int sum, int idx)
{
	if(sum == aim)
		return true;
	if(idx > n)
		return false;
		
	if(solve(sum + s[idx], idx + 1) || solve(sum, idx + 1))
		return true;
		
	return false;
}

int main()
{
	while(~sfi(n))
	{
		mem(s);
		rep(i, 1, n)
			sfi(s[i]);
			
		int ques;
		sfi(ques);
		while(ques--)
		{
			sfi(aim);
			if(solve(0, 1))
				puts("yes");
			else
				puts("no");
		}
	}
	return 0;
}
