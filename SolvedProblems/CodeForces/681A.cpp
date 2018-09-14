#include<cstdio>
#include<iostream>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstdlib>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)
#define mst(a) memset(a, 0, sizeof(a))
#define PNT putchar('\n')

typedef long long LL;

const int INF = 0xffffffff;
const int MAX = 1e5 + 10;

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);

    int n;
    while(~scanf("%d", &n))
    {
        bool flag = false;
        FOR(i, 0, n - 1)
        {
            char s[MAX] = {0};
            int pre, now;
            scanf("%s%d%d", s, &pre, &now);
            if(pre >= 2400 && now > pre)
                flag = true;
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}