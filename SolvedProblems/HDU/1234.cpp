//~ #define LOCAL

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<iostream>
#include<cmath>
#include<cctype>
#include<vector>
#include<set>
#include<queue>

using namespace std;

typedef long long LL;

const int MAX = 1e3 + 10;
const int N = 1e3;
const int INF = 0x3f3f3f3f;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)

struct Node
{
	string id, st;
	Node(string ii = "", string ss = ""):id(ii), st(ss){}
	friend bool operator <(Node a, Node b)
	{
		return a.st < b.st;
	}
};

struct Nodee
{
	string id, en;
	Nodee(string ii = "", string ee = ""):id(ii), en(ee){}
	friend bool operator <(Nodee a, Nodee b)
	{
		return a.en > b.en;
	}
};

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
#endif	//LOCAL

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	rep(i, 1, n)
	{
		int num;
		cin >> num;
		Node first[MAX];
		Nodee second[MAX];
		rep(j, 1, num)
		{
			string id, st, en;
			cin >> id >> st >> en;
			first[j].id = second[j].id = id;
			first[j].st = st;
			second[j].en = en;
		}
		sort(first + 1, first + num + 1);
		sort(second + 1, second + num + 1);
		cout << first[1].id << " " << second[1].id << endl;
	}
	return 0;
}