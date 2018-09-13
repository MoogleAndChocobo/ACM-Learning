#include<cstdio>

typedef long long LL;

#define FOR(i, a, b) for(int i = a; i <= b; i++)

LL f(LL n)
{
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;
    return (n - 1) * (f(n - 1) + f(n - 2));
}

int main()
{
    LL times;
    scanf("%lld", &times);
    while(times--)
    {
        LL n;
        scanf("%lld", &n);
        LL temp = 1;
        FOR(i, 1, n)
            temp *= i;
        printf("%.2lf%%\n", (f(n) / (double)temp) * 100);

    }
    return 0;
}