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

    int m, n;
    while(~scanf("%d%d", &m, &n))
    {
        int ans = 0;
        while(!(m == 0 || n == 0 || (m == 1 && n == 1)))
        {
            ans++;
            if(m >= n)
                m -= 2, n--;
            else
                m--, n -= 2;
        }
        printf("%d\n", ans);
    }
    return 0;
}