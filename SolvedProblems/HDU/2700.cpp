#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <cmath>
#include <cctype>

using namespace std;

typedef long long LL;

const int MAX = 1e4 + 10;

#define rep(i, a, b) for(int i = a; i <=b; i++)
#define dow(i, a, b) for(int i = a; i >=b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf"£¬ &a)
#define sfs(a) scanf("%s", a)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(a) a.begin(),a.end()
#define fli freopen("in.txt", "r", stdin);
#define flo freopen("out.txt", "w",stdout);
#define pb(a) push_back(a)
#define yes puts("yes")
#define no puts("no");
#define Yes puts("Yes")
#define No puts("No")
#define YES puts("YES")
#define NO puts("NO")

int main()
{
#ifdef LOCAL
	//~ fli
	//~ flo
#endif	//LOCAL

	char s[MAX];
	while(~sfs(s) && s[0] != '#')
	{
		int len = strlen(s);
		int cnt = 0;
		rep(i, 0, len - 2)
		{
			if(s[i] == '1')
				cnt++;
			putchar(s[i]);
		}
		if((s[len - 1] == 'o' && cnt % 2 == 0) || (s[len - 1] == 'e' && cnt % 2))
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}