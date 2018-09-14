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

typedef long long LL;

const int MAX = 1e5 + 10;

int bfs()
{

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int sum, m;
    while(~scanf("%d%d", &sum, &m))
    {
        if(sum == 1 && m == 1)
            printf("1\n");
        else
        {
            if(m - 1 >= sum - m)
                printf("%d\n", m - 1);
            else
                printf("%d\n", m + 1);
        }
    }
    return 0;
}