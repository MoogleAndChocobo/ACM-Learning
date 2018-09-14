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
        int s[MAX] = {0};
        int cmp[MAX] = {0};
        FOR(i, 1, n)
        {
            scanf("%d", &s[i]);
            cmp[i] = s[i];
        }
        sort(cmp, cmp + n + 1);
        int st = 1, cnt = 0;
        FOR(i, 1, n)
        {
            if(s[i] != cmp[i])
            {
                st = i;
                for(int j = i + 1; j <= n; j++)
                {
                    if(s[j] <= s[j - 1])
                        cnt++;
                    else
                        break;
                }
                sort(&s[i], &s[i] + cnt + 1);
                break;
            }
        }
        bool flag = true;
        FOR(i, 1, n)
            if(s[i] != cmp[i])
            {
                flag = false;
                break;
            }
        if(flag)
            printf("yes\n%d %d\n", st, st + cnt);
        else
            printf("no\n");
    }
    return 0;
}