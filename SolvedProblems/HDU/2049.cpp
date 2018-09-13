//#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cctype>
#include<cstdlib>
#include<sstream>
#include<cmath>
#include<set>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)
#define mst(a) memset(a, 0, sizeof(a))
#define b_mst(a) memset(a, false, sizeof(a))
#define PNT putchar('\n')

typedef long long LL;

const int MAX = 1e2 + 10;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    LL s[MAX] = {0};
    s[1] = 0;
    s[2] = 1;
    s[3] = 2;
    FOR(i, 3, 20)
        s[i] = (i - 1) * (s[i - 1] + s[i - 2]);

    LL judge[MAX] = {0};
    judge[0] = 1;
    FOR(i, 1, 20)
        judge[i] = i * judge[i - 1];

    LL n;
    while(~scanf("%lld", &n))
    {
        while(n--)
        {
            LL sum, err;
            scanf("%lld%lld", &sum, &err);
            LL ans = s[err];
            ans *= (judge[sum] / judge[err]) / judge[sum - err];
            printf("%lld\n", ans);
        }
    }
    return 0;
}