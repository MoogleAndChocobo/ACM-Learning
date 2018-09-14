//#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cctype>
#include<cstdlib>
#include<sstream>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)
#define mst(a) memset(a, 0, sizeof(a))
#define b_mst(a) memset(a, false, sizeof(a))

typedef long long LL;

const int MAX = 1e2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(~scanf("%d", &n))
    {
        bool hor[MAX];
        bool ver[MAX];
        b_mst(hor);
        b_mst(ver);
        int ans[MAX] = {0};
        int cnt = 0;
        FOR(i, 0, n * n - 1)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            if(!hor[x - 1] && !ver[y - 1])
            {
                ans[cnt++] = i + 1;
                hor[x - 1] = true;
                ver[y - 1] = true;
            }
        }
        FOR(i, 0, cnt - 1)
        {
            printf("%d", ans[i]);
            if(i != cnt - 1)
                printf(" ");
            else
                printf("\n");
        }
    }
    return 0;
}