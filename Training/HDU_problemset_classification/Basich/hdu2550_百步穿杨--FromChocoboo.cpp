/*
	百步穿杨
	Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
	Total Submission(s): 12310    Accepted Submission(s): 4580


	Problem Description
	时维九月,序属三秋,辽军大举进攻MCA山,战场上两军正交锋.辽军统帅是名噪一时的耶律-James,而MCA方则是派出了传统武将中草药123.双方经过协商,约定在十一月八日正午十分进行射箭对攻战.中草药123早早就开始准备,但是他是武将而不是铁匠,造弓箭的活就交给聪明能干的你了,现在告诉你每种弓箭规格,即箭身的长度,以及每种规格弓箭所需要的数目,要求你把需要的弓箭都输出.
	弓箭的基本样子为 ">+---+>",其中"+---+"为箭身,数据保证箭身长度 > 2


	Input
	首先输入一个t,表示有t组数据，跟着t行：
	每行一个N (N < 50 ),接下去有N行,第i行两个整数Ai , Bi,分别代表需要箭身长度为Ai的弓箭Bi枝. (Ai < 30 , Bi < 10 )
	输入数据保证每一个Ai都是不同的.


	Output
	按照箭身的长度从小到大的顺序依次输出所有需要的弓箭,"每一种"弓箭后输出一个空行.


	Sample Input
	1
	4
	3 4
	4 5
	5 6
	6 7


	Sample Output
	>+-+>
	>+-+>
	>+-+>
	>+-+>

	>+--+>
	>+--+>
	>+--+>
	>+--+>
	>+--+>

	>+---+>
	>+---+>
	>+---+>
	>+---+>
	>+---+>
	>+---+>

	>+----+>
	>+----+>
	>+----+>
	>+----+>
	>+----+>
	>+----+>
	>+----+>


	Author
	Teddy


	Source
	2008“缤纷下沙校园文化活动月”之大学生程序设计竞赛暨新生专场


	Recommend
	lcy   |   We have carefully selected several similar problems for you:  2549 2547 2548 2552 2561

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

const int MAX = 1e3 + 10;

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
	int a, b;
	Node(int aa = 0, int bb = 0):a(aa), b(bb){}
	friend bool operator <(Node m, Node n)
	{
		return m.a < n.a;
	}
};

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
		Node s[MAX];

		int n;
		sfi(n);
		rep(i, 1, n)
		{
			scanf("%d%d", &s[i].a, &s[i].b);
		}
		sort(s + 1, s + n + 1);
		rep(i, 1, n)
		{
			rep(j, 1, s[i].b)
			{
				printf(">+");
				rep(k, 1, s[i].a - 2)
					putchar('-');
				puts("+>");
			}
			putchar('\n');
		}
	}
	return 0;
}
