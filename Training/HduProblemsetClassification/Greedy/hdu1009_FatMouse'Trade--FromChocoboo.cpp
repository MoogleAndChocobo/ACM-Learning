/*
	FatMouse' Trade
	Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
	Total Submission(s): 90274    Accepted Submission(s): 31274


	Problem Description
	FatMouse prepared M pounds of cat food, ready to trade with the cats guarding the warehouse containing his favorite food, JavaBean.
	The warehouse has N rooms. The i-th room contains J[i] pounds of JavaBeans and requires F[i] pounds of cat food. FatMouse does not have to trade for all the JavaBeans in the room, instead, he may get J[i]* a% pounds of JavaBeans if he pays F[i]* a% pounds of cat food. Here a is a real number. Now he is assigning this homework to you: tell him the maximum amount of JavaBeans he can obtain.


	Input
	The input consists of multiple test cases. Each test case begins with a line containing two non-negative integers M and N. Then N lines follow, each contains two non-negative integers J[i] and F[i] respectively. The last test case is followed by two -1's. All integers are not greater than 1000.


	Output
	For each test case, print in a single line a real number accurate up to 3 decimal places, which is the maximum amount of JavaBeans that FatMouse can obtain.


	Sample Input
	5 3
	7 2
	4 3
	5 2
	20 3
	25 18
	24 15
	15 10
	-1 -1


	Sample Output
	13.333
	31.500


	Author
	CHEN, Yue


	Source
	ZJCPC2004


	Recommend
	JGShining   |   We have carefully selected several similar problems for you:  1050 1051 2037 1052 1002
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

const int MAX = 1e4 + 10;
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

struct Node
{
	int num, cost;
	double per;
	Node(int nn = 0, int cc = 0, double pp = 0.0):num(nn), cost(cc), per(pp){}
	friend bool operator <(Node a, Node b)
	{
		return a.per > b.per;
	}
};

int main()
{
#ifdef LOCAL
	//~ fli
	//~ flo
#endif	//LOCAL

	int m, n;
	while(~scanf("%d%d", &m, &n))
	{
		if(!(n + 1) && !(m + 1))
			break;
		Node s[MAX];
		rep(i, 1, n)
		{
			scanf("%d%d", &s[i].num, &s[i].cost);
			s[i].per = (double)s[i].num / (double)s[i].cost;
		}
		sort(s + 1, s + n + 1);
		double ans = 0;
		rep(i, 1, n)
		{
			if(s[i].cost < m)
			{
				ans += s[i].num;
				m -= s[i].cost;
			}
			else
			{
				ans += m / (double)s[i].cost * (double)s[i].num;
				m = 0;
				break;
			}
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}
