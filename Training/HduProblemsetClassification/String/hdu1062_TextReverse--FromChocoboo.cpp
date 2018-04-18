/*
	Text Reverse
	Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
	Total Submission(s): 36180    Accepted Submission(s): 14208


	Problem Description
	Ignatius likes to write words in reverse way. Given a single line of text which is written by Ignatius, you should reverse all the words and then output them.


	Input
	The input contains several test cases. The first line of the input is a single integer T which is the number of test cases. T test cases follow.
	Each test case contains a single line with several words. There will be at most 1000 characters in a line.


	Output
	For each test case, you should output the text which is processed.


	Sample Input
	3
	olleh !dlrow
	m'I morf .udh
	I ekil .mca


	Sample Output
	hello world!
	I'm from hdu.
	I like acm.

	Hint

	Remember to use getchar() to read '\n' after the interger T, then you may use gets() to read a line and process it.



	Author
	Ignatius.L


	Recommend
	We have carefully selected several similar problems for you:  1073 1088 1002 1042 1161
*/



#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<iostream>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<list>
#include<cctype>
#include<ctime>
#include<functional>
#include<cmath>

using namespace std;

typedef unsigned U;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> pii;

const int MAX = 1e3 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const LL LINF = 0x3f3f3f3f3f3f3f;

#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfc(a) scanf("%c", &c)
#define sfs(a) scanf("%s", a)
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))

int main()
{

#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif    //LOCAL

    //ios::sync_with_stdio(false);
    //cin.tie(0);

    int n;
    while(~sfi(n))
    {
        getchar();
        rep(i, 1, n)
        {
            char s[MAX];
            gets(s);
            int len = strlen(s);
            s[len] = '\n';
            string tmp;
            set<string> st;
            st.insert(tmp);
            rep(i, 0, len)
            {
                if(s[i] == '\n')
                {
                    if(st.find(tmp) == st.end())
                    {
                        int length = tmp.size();
                        dow(i, length - 1, 0)
                            putchar(tmp[i]);
                        tmp.clear();
                    }
                }
                else if(s[i] == ' ')
                {
                    if(st.find(tmp) == st.end())
                    {
                        int length = tmp.size();
                        dow(i, length - 1, 0)
                            putchar(tmp[i]);
                        tmp.clear();
                    }
                    putchar(' ');
                }
                else
                {
                    tmp += s[i];
                }
            }
            putchar('\n');
        }

    }
    return 0;
}
