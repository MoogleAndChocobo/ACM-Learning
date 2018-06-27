#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <bitset>
#include <deque>
#include <cmath>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

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
#define sync ios::sync_with_stdio(0); cin.tie(0);

const int MAXN = 1000 + 5;
const double EPS = 1e-6;
const double PI = acos(-1.0);

const LL MOD = 1000 + 50;

const int MAX = 2 * 100000 + 50;
const int N = 2 * 100000;

set<LL> vec;
map<LL, int> mpl;
map<LL, int> mpr;
LL ans[MAX];

int main()
{
    int n;
    sfi(n);
    rep(i, 1, n)
    {
        LL l, r;
        scanf("%lld%lld", &l, &r);
        vec.insert(l);
        vec.insert(r);
        mpl[l]++;
        mpr[r]++;
    }

    set<LL>::iterator it = vec.begin();
    ans[mpl[*it]]++;
    LL sum = mpl[*it] - mpr[*it];
    LL pre = *it;
    for(++it; it != vec.end(); ++it)
    {
        if(sum)
            ans[sum] += *it - pre - 1;
        LL l = mpl[*it];
        LL r = mpr[*it];
        ans[sum + l]++;
        sum += l - r;
        pre = *it;
    }
    rep(i, 1, n)
    {
        printf("%lld%c", ans[i], i != n ? ' ' : '\n');
    }

    return 0;
}
