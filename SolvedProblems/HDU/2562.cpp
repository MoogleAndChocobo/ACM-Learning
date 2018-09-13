/*
	�޽�����
	Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
	Total Submission(s): 6020    Accepted Submission(s): 3801


	Problem Description
	����ĩ�꣬�鳼�������¹���Ȩ��������ؽ���ɾ��ٷ���ʱ��ս���������������𣬰����Ұ���������������ڶ�������ʿȺ�����������־ʿ�Ƽ���Ӧ,����Ӱ�ӡ�
	ֵ��Σ������֮���һ�����������ĵط�---MCAɽ��һλ�����˳�<Ӣ���������>��������Ϊ���������о�������������һ�׵罻��֮ҹ��ȷ������˵����ط�Ľ����˺���ʽ��

	���� f(x, y, m, n) = sqrt(x*x + y*y + m*m + n*n - 2*m*x - 2*n*y);
	hint : sqrt��ʾ��������sqrt��4�� = 2�� sqrt��16�� = 4��

	������x��yΪλ�ñ�����m��nΪ���Գ�����
	�����˺� = f(x, y, a, b) + f(x, y, c, d)��
	���������޴��ޱȣ�ʵ�ѿ��ƣ���������֪�������˺�����С�˺�ֵ��



	Input
	��������һ��t,��ʾ��t�����ݣ�����t�У�
	�����ĸ�ʵ��a��b��c��d��С�ڵ���100


	Output
	�����������С�˺�ֵM������С�����һλ
	������ʹ��.1lf��


	Sample Input
	2
	0 0 3 4
	4 0 0 3


	Sample Output
	5.0
	5.0


	Author
	Ӣ���������


	Source
	2008���ͷ���ɳУ԰�Ļ���¡�֮��ѧ��������ƾ���������ר��


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
#define sfd(a) scanf("%lf"�� &a)
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
		char s[MAX];
		sfs(s);
		int len = strlen(s);
		for(int i = 0; i < len; i += 2)
		{
			swap(s[i], s[i + 1]);
		}
		printf("%s\n", s);
	}
	return 0;
}