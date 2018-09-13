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

int n;
char v[100005];
ll sum1, sum2;
int group[100005];

void left(int i)
{
	if (v[i] == '1') group[i] = 3;
	else group[i] = 1;
}

void right(int i)
{
	if (v[i] == '1') group[i] = 4;
	else group[i] = 2;
}

int main()
{
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		scanf("%s", v);
		sum1 = sum2 = 0;
		for (int i = n, j = n - 1; i >= 1; i--, j--) {
			if (sum1 == sum2) {
				sum1 += i;
				left(j);
			}
			else if (sum1 > sum2) {
				sum2 += i;
				right(j);
			}
			else {
				sum1 += i;
				left(j);
			}
		}
		if (sum1 == sum2) {
			for (int i = 0; i < n; i++) {
				printf("%d", group[i]);
			}
			printf("\n");
		}
		else {
			printf("-1\n");
		}
	}
}