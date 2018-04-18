/*
	无剑无我
	Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
	Total Submission(s): 6020    Accepted Submission(s): 3801


	Problem Description
	北宋末年，奸臣当道，宦官掌权，外侮日亟，辽军再犯。时下战火连连，烽烟四起，哀鸿遍野，民不聊生，又有众多能人异士群起而反，天下志士云集响应,景粮影从。
	值此危急存亡之秋，在一个与世隔绝的地方---MCA山上一位江湖人称<英雄哪里出来>的人正在为抗击辽贼研究剑法，终于于一雷电交加之夜精确计算出了荡剑回锋的剑气伤害公式。

	定义 f(x, y, m, n) = sqrt(x*x + y*y + m*m + n*n - 2*m*x - 2*n*y);
	hint : sqrt表示开方，即sqrt（4） = 2； sqrt（16） = 4；

	（其中x，y为位置变量，m，n为属性常量）
	剑气伤害 = f(x, y, a, b) + f(x, y, c, d)；
	剑气威力巨大无比，实难控制，现在他想知道剑气伤害的最小伤害值。



	Input
	首先输入一个t,表示有t组数据，跟着t行：
	输入四个实数a，b，c，d均小于等于100


	Output
	输出剑气的最小伤害值M，保留小数点后一位
	（可以使用.1lf）


	Sample Input
	2
	0 0 3 4
	4 0 0 3


	Sample Output
	5.0
	5.0


	Author
	英雄哪里出来


	Source
	2008“缤纷下沙校园文化活动月”之大学生程序设计竞赛暨新生专场


	Recommend
	lcy   |   We have carefully selected several similar problems for you:  2548 2549 2552 2555 2567

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
	rep(i, 1, T)
	{
		double a, b, m, n;
		scanf("%lf%lf%lf%lf", &a, &b, &m, &n);
		printf("%.1lf\n", hypot(a - m, b - n));
	}
	return 0;
}
