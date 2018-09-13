#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define sfs(a) scanf("%s", a)
#define sfs(a) scanf("%d", &a)

const int MAX = 1e3 + 10;

struct Node
{
    string s;
    int v;
    friend bool operator <(Node a, Node b)
    {
    	if(a.v != b.v)
			return a.v > b.v;
		else
			return a.s < b.s;
    }
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while(T--)
	{
		Node s[110];
		vector<string> ans;
        int n, m;
        cin >> n >> m;
        rep(i, 1, n)
			cin >> s[i].s >> s[i].v;
        sort(s + 1, s + n + 1);
        LL pro = m;
        LL sum = 0;
        rep(i, 1, m)
        {
        	LL tmp = pro * (LL) s[i].v;
			sum += tmp;
			ans.push_back(s[i].s);
            pro--;
        }
        cout << sum;
		rep(i, 1, m)
		{
            cout << " " << ans[i - 1];
		}
		cout << endl;
	}
    return 0;
}