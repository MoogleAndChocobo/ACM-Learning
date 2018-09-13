#include <bits/stdc++.h>


#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;


#define pb(a)        push_back(a)
#define mp(a, b)     make_pair(a, b)
#define fi           first
#define se           second
#define all(a)       a.begin(),a.end()
#define szz(a)       (int)a.size()
#define endl         '\n'

typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<db, db> pdd;

const ll MOD = 1e9 + 7;
const int INF = 0x7fffffff;
const ll LLINF = 0x7fffffffffffffff;
const db PI = acos(-1.0);
const db eps = 1e-7;

const char k[3][4] = {
	"0O0",
	"/|\\",
	"(0)"
};

int n, m;
char v[105][105];


bool check(int x, int y)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			int f = x - 2 + i, t = y - 2 + j;
			if (f >= 0 && f < n && t >= 0 && t < m && k[i][j] == v[f][t])
				return 1;
		}
	return 0;
}



int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%s", v[i]);
		
		ll ans = 0;
		
		for (int i = 0; i < n + 2; i++)
			for (int j = 0; j < m + 2; j++)
				if (check(i, j)) {
					++ans;
				}
		printf("%lld\n", ans);
	}
    return 0;
}