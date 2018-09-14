#include<cstdio>

int main()
{
    long long sum, num;
    scanf("%lld%lld", &sum, &num);
    long long mx = sum - num;
    mx = (1 + mx) * mx / 2;
    long long n = sum / num - 1;
    long long mn;
    if(sum % num == 0)
        mn = num * (1 + n) * n / 2;
    else
    {
        long long temp = sum % num;
        mn = (2 + n) * (n + 1) / 2 * temp + (1 + n) * n / 2 * (num - temp);
    }
    printf("%lld %lld\n", mn, mx);
    return 0;
}