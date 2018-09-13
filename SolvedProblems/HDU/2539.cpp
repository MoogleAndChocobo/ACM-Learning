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

const int MOD = 1e9 + 9;
const int MAX = 1e4 + 10;
const int INF = 0x3f3f3f3f;
const int N = 1e3;
const LL LINF = 0x3f3f3f3f3f3f3f;

int main()
{
#ifdef LOCAL
	//~ fli
	//~ flo
#endif	//LOCAL



	int n;
	while(~sfi(n) && n)
	{
		getchar();
		int reco[MAX] = {0}, rect[MAX] = {0};
		rep(i, 1, n)
		{
			char s[MAX];
			fgets(s, 1000, stdin);
			//~ printf("%s", s);
			int len = strlen(s);
			bool flag = true;
			if(len > 8)
				flag = !(s[len - 7] == 'o' && s[len - 8] == 'n' && s[len - 9] == ' ');
			if(i % 2)
				reco[(i + 1) / 2] = (int)flag + 1;
			else
				rect[(i + 1) / 2] = (int)flag + 1;
		}
		int lmt = (n + 1) / 2;
		rep(i, 1, lmt)
			printf("%d ", i);
		puts("Score");
		int ca = 0, cb = 0;
		rep(i, 1, lmt)
		{
			if(reco[i] == 2)
			{
				ca++;
				printf("O ");
			}
			else if(reco[i] == 1)
				printf("X ");
			else
				printf("- ");
		}
		printf("%d\n", ca);
		rep(i, 1, lmt)
		{
			if(rect[i] == 2)
			{
				cb++;
				printf("O ");
			}
			else if(rect[i] == 1)
				printf("X ");
			else
				printf("- ");
		}
		printf("%d\n", cb);
	}
	return 0;
}