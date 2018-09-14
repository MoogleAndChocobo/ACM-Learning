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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(~scanf("%d", &n))
    {
        int s[MAX] = {0};
        FOR(i, 1, n)
            scanf("%d", &s[i]);
        int mx = 1;
        FOR(i, 1, n)
        {
            int cnt = 0;
            for(int j = i; j <= n && j != -1; j = s[j])
                cnt++;
            mx = max(mx, cnt);
        }
        printf("%d\n", mx);
    }
    return 0;
}