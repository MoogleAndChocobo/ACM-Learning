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

const int MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(~scanf("%d", &n))
    {
        LL s[MAX] = {0};
        FOR(i, 0, n - 1)
            scanf("%lld", &s[i]);
        sort(s, s + n);
        int cnt = 1;
        LL sum = s[0];
        FOR(i, 1, n - 1)
        {
            if(sum <= s[i])
            {
                cnt++;
                sum += s[i];
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}