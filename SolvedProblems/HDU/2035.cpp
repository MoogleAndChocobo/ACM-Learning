#include <stdio.h>

#define MOD 1000

long long f(long long a, long long b);

int main()
{
    long long a, b;
    while(~scanf("%lld%lld", &a, &b))
    {
        if(a == 0 && b == 0)
            break;
        printf("%lld\n", f(a, b));
    }
}

long long f(long long a, long long b)
{
    long long c = 1;
    while(b)
    {
        if(b % 2)
        {
            c *= a;
            c %= MOD;
        }
        a *= a;
        a %= MOD;
        b >>= 1;
    }
    return c;
    
}