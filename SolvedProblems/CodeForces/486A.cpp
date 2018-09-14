#include<cstdio>

int main()
{
    long long n;
    scanf("%lld", &n);
    if(n % 2)
        printf("%lld\n", (n - 1) / 2 - n);
    else
        printf("%lld\n", n / 2);
    return 0;
}