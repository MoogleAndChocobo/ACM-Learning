#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

typedef long long LL;
typedef long long ll;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define mem(a) memset(a, 0, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define sync ios::sync_with_stdio(0); cin.tie(0);

const int MAX = 1e3 + 5;

bool check(int a)
{
	return a >= 0 && a <= 255;
}

int main()
{
	char ip[MAX];
	while(gets(ip) != NULL)
	{
		int a, b, c, d;
		sscanf(ip, "%d.%d.%d.%d", &a, &b, &c, &d);
		bool f = false;
		if(check(a) && check(b) && check(c) && check(d))
		{
			char s[MAX];
			sprintf(s, "%d.%d.%d.%d", a, b, c, d);
			if(!strcmp(s, ip))
				f = true;
		}
		puts(f ? "YES" : "NO");
	}
	return 0;
}