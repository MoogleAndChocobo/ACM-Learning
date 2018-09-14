#include<cstdio>

int main()
{
    long long x;
    scanf("%lld", &x);
    int cnt = 1;
    while(x != 1)
    {
        if(x % 2)
            cnt++;
        x >>= 1;
    }
    printf("%d", cnt);
    return 0;
}