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

const int MAX = 15 * 1e4 + 10;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, len;
    while(~scanf("%d%d", &n, &len))
    {
        LL s[MAX] = {0};
        FOR(i, 1, n)
        {
            LL temp;
            scanf("%lld", &temp);
            s[i] = s[i - 1] + temp;
        }
        LL ans = INF;
        int index = 1;
        FOR(i, len, n)
            if(ans >= s[i] - s[i - len])
            {
                index = i - len + 1;
                ans = s[i] - s[i - len];
            }
        printf("%d\n", index);
    }
    return 0;
}