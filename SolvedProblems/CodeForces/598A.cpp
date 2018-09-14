#include<cstdio>
#include<cmath>

typedef long long LL;

int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        LL x;
        scanf("%lld", &x);
        LL ans = (1 + x) * x / 2;
        LL temp = 1;
        while(temp <= x)
        {
            ans -= temp * 2;
            temp *= 2;
        }
        printf("%lld\n", ans);
    }
    return 0;
}