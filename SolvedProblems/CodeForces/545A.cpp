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

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)
#define mst(a) memset(a, 0, sizeof(a))
#define b_mst(a) memset(a, false, sizeof(a))
#define PNT putchar('\n')

typedef long long LL;

const int MAX = 1e2 + 10;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(~scanf("%d", &n))
    {
        int s[MAX][MAX] = {0};
        FOR(i, 1, n)
            for(int j = 1; j <= n; j++)
                scanf("%d", &s[i][j]);
        int cnt = 0;
        int ans[MAX] = {0};
        FOR(i, 1, n)
        {
            bool flag = true;
            for(int j = 1; j <= n; j++)
            {
                if(s[i][j] == 3 || s[i][j] == 1)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                ans[cnt++] = i;
        }
        printf("%d\n", cnt);
        FOR(i, 0, cnt - 1)
        {
            printf("%d", ans[i]);
            if(i != cnt - 1)
                printf(" ");
            else
                PNT;
        }
    }
    return 0;
}