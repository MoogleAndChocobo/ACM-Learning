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

const int MAX = 1e4 + 5;

int main()
{
	int kase = 0;
	char s[MAX];
	while(~sfs(s) && strcmp(s, "STOP"))
	{
		int len = strlen(s);
		int lmt = len / 2;
		bool f = true;
		if(len == 1)
			goto N;
		rep(i, 0, lmt - 1)
		{
			if(s[i] != s[len - i - 1])
			{
				f = false;
				break;
			}
		}
		N:;
		printf("#%d: %s\n", ++kase, f ? "YES" : "NO");
	}
	return 0;
}