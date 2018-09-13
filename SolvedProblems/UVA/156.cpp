#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%lld", a)

const int MAX = 1e4 + 5;

struct Word
{
	string pre, ord;
} word[MAX];

map<string,int> mp;
vector<string> vec;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	int cnt = 0;
	while(cin >> s && s != "#")
	{
		int len = s.size();
		word[++cnt].pre = s;
		rep(i, 0, len - 1)
			s[i] = tolower(s[i]);
		sort(s.begin(), s.end());
		mp[s]++;
		word[cnt].ord = s;
	}
	rep(i, 1, cnt)
	{
		if(mp[word[i].ord] == 1)
			vec.push_back(word[i].pre);
	}
	sort(vec.begin(), vec.end());
	int len = vec.size();
	rep(i, 0, len - 1)
		cout << vec[i] << endl;
	return 0;
}