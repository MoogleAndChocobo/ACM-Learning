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
        int temp;
        bool flag = false;
        FOR(i, 1, n)
        {
            scanf("%d", &temp);
            if(temp == 1)
                flag = true;
        }
        if(flag)
            printf("-1\n");
        else
            printf("1\n");
    }
    return 0;
}