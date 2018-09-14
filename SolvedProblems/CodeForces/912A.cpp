#include<cstdio>

typedef long long LL;

int main()
{
    LL m, n;
    LL x, y, z;
    scanf("%lld%lld%lld%lld%lld", &m, &n, &x, &y, &z);
    LL sum1 = 2 * x + y;
    LL sum2 = 3 * z + y;
    LL sum = 0;
    if(sum1 > m)
        sum += sum1 - m;
    if(sum2 > n)
        sum += sum2 - n;
    printf("%lld\n", sum);
    return 0;
}