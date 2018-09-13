#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<iostream>

using namespace std;

typedef long long LL;

const int MAX = 1e2 + 10;
const int N = 200;
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define pb(a) push_back(a)
#define mst(a, b) memset(a, b, sizeof(a))
#define sfl(a) scanf("%lld", &a)

struct Milk
{
	string name;
	int cost, volume;
	Milk(string nn = "", int cc = 0, int vv = 0):name(nn), cost(cc), volume(vv){}
	friend bool operator <(Milk a, Milk b)
	{
		int aday = a.volume / N;
		if(aday > 5)
			aday = 5;
		int bday = b.volume / N;
		if(bday > 5)
			bday = 5;
		double pera = (double)a.cost / aday;
		double perb = (double)b.cost / bday;
		if(pera != perb)
			return pera < perb;
		else
			return a.volume > b.volume;
	}
};

int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	rep(i, 1, T)
	{
		int n;
		cin >> n;
		string name;
		int cost, volume;
		cin >> name >> cost >> volume;
		Milk ans =  Milk(name, cost, volume);
		rep(i, 2, n)
		{
			cin >> name >> cost >> volume;
			Milk tmp = Milk(name, cost, volume);
			ans = min(ans, tmp);
		}
		cout << ans.name << endl;
	}
	return 0;
}