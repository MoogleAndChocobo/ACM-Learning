#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cctype>
#include <iostream>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define sfs(a) scanf("%s", a)
#define pb(a) push_back(a)
#define all(a) a.begin(),a.end()
#define sync ios::sync_with_stdio(false); cin.tie(0);

const int MAX = 1e5 + 5;
const int INF = 1e5;

map<string, vector<string> > mp;

bool cmp(string a, string b)
{
	int la = a.size(), lb = b.size();
	if(la != lb)
		return la > lb;
	else
		return a > b;
}

int main()
{
	sync;
	
	set<string> per;
	
	int n;
	cin >> n;
	rep(i, 1, n)
	{
		string name;
		int num;
		cin >> name >> num;
		per.insert(name);
		while(num--)
		{
			string phone;
			cin >> phone;
			mp[name].push_back(phone);
		}
	}
	
	int perlen = per.size();
	for(set<string>::iterator it = per.begin(); it != per.end(); it++)
	{
		sort(all(mp[*it]), cmp);
		int len = mp[*it].size();
		rep(i, 1, len - 1)
		{
			string small = mp[*it][i];
			int slen = small.size();
			bool f = false;
			dow(j, i - 1, 0)
			{
				string large = mp[*it][j];
				//~ cout << small << " " << large << endl;
				if(large == "#")
					continue;
				int llen = large.size();
				bool tmpf = true;
				rep(k, 1, slen)
				{
					//~ cout << "::" << small[slen - k] << " " << large[llen - k] << endl;
					if(small[slen - k] != large[llen - k])
					{
						tmpf = false;
						break;
					}
				}
				if(tmpf)
				{
					f = true;
					break;
				}
			}
			if(f)
			{
				mp[*it][i] = "#";
				//~ cout << "ok" << endl;
			}
		}
	}
	
	cout << perlen << endl;
	for(set<string>::iterator it = per.begin(); it != per.end(); it++)
	{
		cout << *it << " ";
		int len = mp[*it].size();
		vector<string> ans;
		rep(i, 0, len - 1)
		{
			string now = mp[*it][i];
			if(now != "#")
				ans.push_back(now);
		}
		int anslen = ans.size();
		cout << anslen;
		rep(i, 0, anslen - 1)
		{
			cout << " " << ans[i];
		}
		cout << endl;
	}
	return 0;
}