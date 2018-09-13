

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <list>
#include <cctype>
#include <ctime>
#include <functional>
#include <cmath>

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

struct Ques
{
	string name;
	int cnt;
	int sumpunish;
	friend bool operator <(Ques a, Ques b)
	{
		if(a.cnt != b.cnt)
			return a.cnt < b.cnt;
		else if(a.sumpunish != b.sumpunish)
			return a.sumpunish > b.sumpunish;
		else
			return a.name > b.name;
	}
};

priority_queue<Ques> st;

int main()
{
	
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	//ios::sync_with_stdio(false);
	//cin.tie(0);


	int n, punish;
	cin >> n >> punish;
	
	string name;
	while(cin >> name)
	{
		Ques q;
		q.name = name;
		q.cnt = q.sumpunish = 0;
		string tmp;
		rep(i, 1, n)
		{
			cin >> tmp;
			int len = tmp.size();
			if(tmp[len - 1] != ')' && tmp[0] != '-' && tmp[0] != '0')
			{
				q.cnt++;
				int mypow = 1;
				dow(i, len - 1, 0)
				{
					q.sumpunish += mypow * (tmp[i] - '0');
					mypow *= 10;
				}
			}
			else if(tmp[len - 1] == ')')
			{
				q.cnt++;
				int numa = 0, numb = 0;
				rep(i, 0, len - 1)
				{
					if(tmp[i] == '(')
					{
						numa = i;
						numb = len - numa - 2;
						break;
					}
				}
				//cout << tmp << ":" << numa << " " << numb << endl;
				int mypow = 1;
				dow(i, len - numb - 3, 0)
				{
					q.sumpunish += mypow * (tmp[i] - '0');
					mypow *= 10;
				}
				mypow = 1;
				dow(i, len - 2, len - 1 - numb)
				{
					q.sumpunish += mypow * (tmp[i] - '0') * punish;
					mypow *= 10;
				}
			}
		}
		st.push(q);
	}

	while(!st.empty())
	{
		Ques it = st.top();
		st.pop();
		int len = it.name.size();
		cout << it.name;
		rep(i, len + 1, 10)
			putchar(' ');
		printf(" %2d %4d\n", it.cnt, it.sumpunish);
	}
	return 0;
}