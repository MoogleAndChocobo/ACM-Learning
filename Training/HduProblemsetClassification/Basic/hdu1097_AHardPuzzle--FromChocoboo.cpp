/*
	A hard puzzle
	Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
	Total Submission(s): 48264    Accepted Submission(s): 17723


	Problem Description
	lcy gives a hard puzzle to feng5166,lwg,JGShining and Ignatius: gave a and b,how to know the a^b.everybody objects to this BT problem,so lcy makes the problem easier than begin.
	this puzzle describes that: gave a and b,how to know the a^b's the last digit number.But everybody is too lazy to slove this problem,so they remit to you who is wise.


	Input
	There are mutiple test cases. Each test cases consists of two numbers a and b(0<a,b<=2^30)


	Output
	For each test case, you should output the a^b's last digit number.


	Sample Input
	7 66
	8 800


	Sample Output
	9
	6


	Author
	eddy


	Recommend
	JGShining   |   We have carefully selected several similar problems for you:  1002 1159 1042 1087 1060
*/


#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>

using namespace std;

typedef long long LL;

const int MAX = 1e2 + 10;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define pb(a) push_back(a)
#define mst(a, b) memset(a, b, sizeof(a))
#define sfl(a) scanf("%lld", &a)

int main()
{
#ifdef LOCAL
    //~ freopen("in.txt", "r", stdin);
#endif    //LOCAL

    LL m, n;
    while(~scanf("%lld%lld", &n, &m))
    {
        n %= 10;
        if(n == 0)
            puts("0");
        else if(n == 1)
            puts("1");
        else if(n == 2)
        {
            int s[MAX] = {6, 2, 4, 8};
            printf("%d\n", s[m % 4]);
        }
        else if(n == 3)
        {
            int s[MAX] = {1, 3, 9, 7};
            printf("%d\n", s[m % 4]);
        }
        else if(n == 4)
        {
            int s[MAX] = {6, 4};
            printf("%d\n", s[m % 2]);
        }
        else if(n == 5)
            puts("5");
        else if(n == 6)
            puts("6");
        else if(n == 7)
        {
            int s[MAX] = {1, 7, 9, 3};
            printf("%d\n", s[m % 4]);
        }
        else if(n == 8)
        {
            int s[MAX] = {6, 8, 4, 2};
            printf("%d\n", s[m % 4]);
        }
        else if(n == 9)
        {
            int s[MAX] = {1, 9};
            printf("%d\n", s[m % 2]);
        }
    }
    return 0;
}
