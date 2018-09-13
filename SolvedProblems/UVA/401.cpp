//~ #define LOCAL

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<iostream>
#include<vector>
#include<sstream>
#include<map>
#include<set>
#include<cmath>
#include<cctype>
#include<functional>
#include<ctime>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LF;
typedef unsigned U;

const int dirnd[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
const int dirrd[6][3] = {{0,0,1},{0,0,-1},{1,0,0},{-1,0,0},{0,1,0},{0,-1,0}};
const int MAX = 1e4 + 10;
const int N = 1e3;
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f;

#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfu(a) scanf("%llu", &a)
#define sfd(a) scanf("%ld", &a)
#define sfs(a) scanf("%s", a)
#define sfc(a) getchar(a)
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))

char check(char c)
{
	if(c == 'A' || c == 'H' || c == 'I' || c == 'M' || c == 'O' || c == 'T' || c == 'U' || c == 'V' || c == 'W' || c == 'X' || c == 'Y' || c == '1' || c == '8')
		return c;
	if(c == 'E')
		return '3';
	if(c == '3')
		return 'E';
	if(c == 'J')
		return 'L';
	if(c == 'L')
		return 'J';
	if(c == 'S')
		return '2';
	if(c == '2')
		return 'S';
	if(c == 'Z')
		return '5';
	if(c == '5')
		return 'Z';
	return ' ';
}

int main()
{
	  
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL


	char s[MAX] = {0};
	while(~scanf("%s", s))
	{
		int len = strlen(s);
		int lmt = len / 2;
		bool flag = true;
		rep(i, 0, lmt)
		{
			if(s[i] != s[len - i - 1])
			{
				flag = false;
				break;
			}
		}
		bool judge = true;
		rep(i, 0, lmt)
		{
			if(s[len - i - 1] != check(s[i]))
			{
				judge = false;
				break;
			}
		}
		printf("%s -- is ", s);
		if(!flag && !judge)
			printf("not a palindrome.\n");
		else if(flag && judge)
			printf("a mirrored palindrome.\n");
		else if(flag)
			printf("a regular palindrome.\n");
		else
			printf("a mirrored string.\n");
		putchar('\n');
	}
	return 0;
}