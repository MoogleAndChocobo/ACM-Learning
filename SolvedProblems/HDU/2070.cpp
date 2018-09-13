#include <stdio.h>

int main()
{
    int n;
    long long s[51] = {0};
    s[0] = 0;
    s[1] = 1;
    for(int i = 2; i < 51; i++)
        s[i] = s[i - 1] + s[i - 2];
    while(~scanf("%d", &n))
    {
        if(n == -1)
            break;
        printf("%lld\n", s[n]);
    }
}