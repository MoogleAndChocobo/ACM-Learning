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

char check(char c)
{
	if(c == 'b')
		return ' ';
	if(c == 'q')
		return ',';
	if(c == 't')
		return '!';
	if(c == 'm')
		return 'l';
	if(c == 'i')
		return 'e';
	if(c == 'c')
		return 'a';
	if(c == 'a')
		return 'c';
	if(c == 'e')
		return 'i';
	if(c == 'l')
		return 'm';
	return c;
}

int main()
{
	char s[MAX];
	while(~sfs(s))
	{
		int len = strlen(s);
		rep(i, 0, len - 1)
			putchar(check(s[i]));
		putchar('\n');
	}
	return 0;
}