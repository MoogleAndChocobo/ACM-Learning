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

typedef long long LL;

const int INF = 0xffffffff;
const int MAX = 1e5 + 10;

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);

    LL n;
    while(~scanf("%lld", &n))
    {
        LL s[MAX] = {0};
        LL pre, ans, egy, now;
        pre = ans = egy = now = 0;
        FOR(i, 1, n)
        {
            scanf("%lld", &now);
            if(now <= pre)
                egy += pre - now;
            else
            {
                if(now - pre >= egy)
                {
                    ans += now - pre - egy;
                    egy = 0;
                }
                else
                    egy -= now - pre;
            }
            pre = now;
        }
        printf("%lld\n", ans);
    }
    return 0;
}