/*
	Encoding
	Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
	Total Submission(s): 52062    Accepted Submission(s): 23164


	Problem Description
	Given a string containing only 'A' - 'Z', we could encode it using the following method:

	1. Each sub-string containing k same characters should be encoded to "kX" where "X" is the only character in this sub-string.

	2. If the length of the sub-string is 1, '1' should be ignored.


	Input
	The first line contains an integer N (1 <= N <= 100) which indicates the number of test cases. The next N lines contain N strings. Each string consists of only 'A' - 'Z' and the length is less than 10000.


	Output
	For each test case, output the encoded string in a line.


	Sample Input
	2
	ABC
	ABBCCC


	Sample Output
	ABC
	A2B3C


	Author
	ZHANG Zheng


	Recommend
	JGShining   |   We have carefully selected several similar problems for you:  1002 1018 1009 1039 1073
*/


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

const int MAX = 2e4;
const int N = 2e4;

#define rep(i, a, b) for(int i = a; i <=b; i++)
#define dow(i, a, b) for(int i = a; i >=b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf"， &a)
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


	int T;
	sfi(T);
	rep(kase, 1, T)
	{
		char s[MAX];
		sfs(s);
		int len = strlen(s);
		rep(i, 1, len - 1)
		{
			if(s[i] == s[i - 1])
			{
				int cnt = 0;
				rep(j, i - 1, len - 1)
				{
					if(s[j] == s[i - 1])
						cnt++;
					else
						break;
				}
				printf("%d%c", cnt, s[i - 1]);
				i = i - 2 + cnt;
				s[i] = '?';
			}
			else
			{
				if(s[i - 1] != '?')
					putchar(s[i - 1]);
			}
		}
		if(s[len - 1] != '?')
			putchar(s[len - 1]);
		putchar('\n');
	}
	return 0;
}
