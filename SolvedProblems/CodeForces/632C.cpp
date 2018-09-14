#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <cctype>
#include <iostream>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define sfd(a) scanf("%lf", &a)
#define pb(a) push_back(a)

const int MAX = 5e4 + 5;
const int N = 100;

string s[MAX];

bool cmp(string a, string b)
{
	return a + b < b + a;
}

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
	//~ freopen("out.txt", "w", stdout);
#endif

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	rep(i, 1, n)
		cin >> s[i];
	sort(s + 1, s + n + 1, cmp);
	rep(i, 1, n)
		cout << s[i];
	cout << endl;
	return  0;
}