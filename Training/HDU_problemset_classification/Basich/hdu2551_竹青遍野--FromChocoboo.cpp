/*
	竹青遍野
	Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
	Total Submission(s): 7895    Accepted Submission(s): 4314


	Problem Description
	"临流揽镜曳双魂 落红逐青裙 依稀往梦幻如真 泪湿千里云"
	在MCA山上,除了住着众多武林豪侠之外,还生活着一个低调的世外高人,他本名逐青裙,因为经常被人叫做"竹蜻蜓",终改名逐青,常年隐居于山中,不再见外人.根据山上附近居民所流传的说法,逐青有一个很奇怪的癖好,从他住进来那天开始,他就开始在他的院子周围种竹子,第1个月种1根竹子,第2个月种8根竹子,第3个月种27根竹子...第N个月就种(N^3)根竹子.他说当他种下第X根竹子那一刻,就是他重出江湖之时!告诉你X的值,你能算出逐青的复出会是在第几个月吗?


	Input
	首先输入一个t,表示有t组数据，跟着t行.每行是一个整数X,X < 1000000000


	Output
	输出一个整数n,表示在第n个月复出


	Sample Input
	3
	1
	2
	10


	Sample Output
	1
	2
	3


	Author
	Teddy


	Source
	2008“缤纷下沙校园文化活动月”之大学生程序设计竞赛暨新生专场


	Recommend
	lcy   |   We have carefully selected several similar problems for you:  2547 2549 2552 2548 1796
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
const int N = 1e9;

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

LL s[MAX];

void init()
{
	LL mypow = 1;
	int cnt = 0;
	while(s[cnt] <= (LL)N)
	{
		cnt++;
		s[cnt] = mypow * mypow * mypow + s[cnt - 1];
		mypow++;
	}
	//~ printf("%d\n", cnt);
}

int main()
{
#ifdef LOCAL
	//~ fli
	//~ flo
#endif	//LOCAL

	init();

	int T;
	sfi(T);
	rep(kase, 1, T)
	{
		LL n;
		sfl(n);
		int pos = lower_bound(s + 1, s + 250 + 1, n) - s;
		printf("%d\n", pos);
	}
	return 0;
}
