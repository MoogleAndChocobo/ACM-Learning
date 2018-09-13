#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <iostream>
#include <functional>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)

const int MAX = 1e3 + 5;

int main()
{
	char s[MAX];
	while(fgets(s, 100, stdin) != NULL && s[0] != '#')
	{
		char gt[MAX];
		fgets(gt, 100, stdin);
		int len = strlen(gt);
		if(gt[len - 1] == '\n')
			gt[len] = '\n', len++;
		int la = strlen(s);
		rep(i, 0, la - 1)
		{
			if(s[i] == '\n')
				break;
			int cnt = 0;
			rep(j, 0, len - 1)
			{
				if(gt[j] == s[i])
					cnt++;
			}
			printf("%c %d\n", s[i], cnt);
		}
	}
	return 0;
}