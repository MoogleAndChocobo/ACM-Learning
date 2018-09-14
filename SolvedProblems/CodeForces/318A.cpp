#include<cstdio>

int main()
{
    long long n, k;
    scanf("%lld%lld", &n, &k);
    long long sum = 0;
    if(n % 2 == 0)
    {
        if(k > n / 2)
            sum = (k - n / 2) * 2;
        else
            sum = 2 * k - 1;
    }
    else
    {
        if(k <= n / 2 + 1)
            sum = 2 * k - 1;
        else
            sum = (k - n / 2 - 1) * 2;
    }
    printf("%lld\n", sum);
    return 0;
}