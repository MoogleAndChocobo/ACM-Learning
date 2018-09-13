#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>
#include <math.h>
#include <cmath>
#include <time.h>
#include <string.h>
#include <vector>
#include <set>
#include <deque>
#include <stack>
#include <time.h>
#include <map>
#include <queue>
#include <functional>
#include <cctype>

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


int main()
{
	int t; scanf("%d", &t);
	while (t--) {
		int n, b; scanf("%d%d", &n, &b);
		bool flag = 0;
		while (n--) {
			int k; scanf("%d", &k);
			if ((k + b) % 7 == 0) flag = 1;
		}
		if (flag) puts("Yes");
		else puts("No");
	}
}