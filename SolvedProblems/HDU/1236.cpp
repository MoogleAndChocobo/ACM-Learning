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

struct Student
{
	string id;
	int num;
	Student(string ii = "", int nn = 0):id(ii), num(nn){}
	friend bool operator <(Student a, Student b)
	{
		if(a.num != b.num)
			return a.num > b.num;
		else
			return a.id < b.id;
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
	while(cin >> n && n)
	{
		int sum, lmt;
		cin >> sum >> lmt;
		Student s[MAX];
		int per[MAX] = {0};
		rep(i, 1, sum)
		{
			cin >> per[i];
		}
		rep(i, 1, n)
		{
			string id;
			cin >> id;
			int num;
			cin >> num;
			int score = 0;
			rep(j, 1, num)
			{
				int tmp;
				cin >> tmp;
				score += per[tmp];
			}
			s[i].id = id;
			s[i].num = score;
		}
		sort(s + 1, s + n + 1);
		int cnt = 0;
		rep(i, 1, n)
		{
			if(s[i].num >= lmt)
				cnt++;
			else
				break;
		}
		cout << cnt << endl;
		rep(i, 1, cnt)
		{
			cout << s[i].id << " " << s[i].num << endl;
		}
	}
	return 0;
}