#include <stdio.h>

int main()
{
    int i, n;
    long long s[55];
    while(~scanf("%d", &n))
    {
        s[1] = 3;
        s[2] = 6;
        s[3] = 6;
        for(i = 4; i <= n; i++)
            s[i] = s[i - 1] +s[i - 2] * 2;
        printf("%I64d\n", s[n]);
    }
}