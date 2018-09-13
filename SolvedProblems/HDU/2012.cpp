

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<set>
#include<vector>
#include<cctype>
#include<map>
#include<cmath>

using namespace std;

const int MAX = 1e3 + 10;

#define rep(i, a, b) for(int i = a; i <= b; i++)

bool check(int n)
{
	if(n <= 1)
		return false;
	rep(i, 2, sqrt(n) + 0.5)
	{
		if(n % i == 0)
			return false;
	}
	return true;
}

int gt(int n)
{
	return n * n + n + 41;
}

int main()
{
	int m, n;
	while(scanf("%d%d", &m, &n) == 2 && (m || n))
	{
		bool flag = true;
		rep(i, m, n)
		{
			if(!check(gt(i)))
			{
				flag = false;
				break;
			}
		}
		if(flag)
			printf("OK\n");
		else
			printf("Sorry\n");
	}
	return 0;
}