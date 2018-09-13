#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cctype>
#include<iostream>
#include<iomanip>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

typedef long long ll;
class InputStream
{
public:
	InputStream(){}
	static ll nextLong()
	{
		bool flag = 0;
		char c = getchar();
		while(!isdigit(c) && c != '-')c = getchar();
		if(c == '-')
		{
			flag = 1;
			c = getchar();
		}
		ll x = 0;
		while(isdigit(c))
		{
			x = x * 10 + c - '0';
			c = getchar();
		}
		if(flag)x = -x;
		return x;
	}
	static int nextInt()
	{
		return nextLong();
	}
	friend InputStream & operator >> (InputStream & in, int & x)
	{
		x = in.nextInt();
		return in;
	}
	friend InputStream & operator >> (InputStream & in, ll & x)
	{
		x = in.nextLong();
		return in;
	}
	friend InputStream & operator >> (InputStream & in, double & x)
	{
		scanf("%lf", &x);
		return in;
	}
}in;

int v[100005];

signed main()
{
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &v[i]);
		}
		int l = 1, r = n;
		while (v[l] < v[l + 1] && l < n) ++l;
		while (v[r] < v[r - 1] && r > 1) --r;
		if (l == r && l != 1 && r != n) puts("Yes");
		else puts("No");
	}
}