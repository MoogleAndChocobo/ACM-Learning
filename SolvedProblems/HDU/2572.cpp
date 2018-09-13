#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

typedef long long LL;
typedef long long ll;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define mem(a) memset(a, 0, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define sync ios::sync_with_stdio(0); cin.tie(0);

const int MAX = 1e3 + 5;

int main()
{
	sync

	int T;
	cin >> T;
	rep(kase, 1, T)
	{
		string a, b, c;
		cin >> a >> b >> c;
		string ans = "****************************************************************************************************************************************************8*******************************************************************************************************************8";
		bool f = false;
		int len = a.size();
		{
			rep(i, 0, len - 1)
			{
				string tmp;
				rep(j, i, len - 1)
				{
					tmp += a[j];
					if(tmp.find(b) != -1 && tmp.find(c) != -1)
					{
						f = true;
						if(tmp.size() < ans.size())
							ans = tmp;
						else if(tmp.size() == ans.size())
							ans = min(ans, tmp);
						break;
					}
				}
			}
		}
		if(f)
			cout << ans << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}