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

    double a, b;
    while(~scanf("%lf%lf", &a, &b))
    {
        int n;
        scanf("%d", &n);
        double mn = INF;
        FOR(i, 0 , n - 1)
        {
            double x, y, v;
            scanf("%lf%lf%lf", &x, &y, &v);
            double temp = sqrt((x - a) * (x - a) + (y - b) * (y - b)) / v;
            mn = min(mn, temp);
        }
        printf("%.10lf\n", mn);
    }
    return 0;
}