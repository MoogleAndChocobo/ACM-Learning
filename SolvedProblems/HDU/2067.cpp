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
typedef unsigned long long ULL;

const int MAX = 1e2 + 10;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    LL s[MAX] = {0};
    s[1] = 1;
    s[2] = 1;
    s[3] = 2;
    FOR(i, 4, 36)
    {
        for(int j = 1, k = i - 1; j <= i - 1; j++, k--)
            s[i] += s[j] * s[k];
    }
    FOR(i, 1, 36)
        s[i] *= 2;
    int n;
    int cnt = 1;
    while(~scanf("%d", &n))
    {
        if(n == -1)
            break;
        printf("%d %d %lld\n", cnt++, n, s[n + 1]);
    }
    return 0;
}