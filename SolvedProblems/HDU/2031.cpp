#include <stdio.h>

int main()
{
    int n, r, l, num[32];
    while(~scanf("%d%d", &n, &r))
    {
        if(n < 0)
        {
            printf("-");
            n *= -1;
        }
        l = 0;
        while(n)
        {
            l++;
            num[32 - l] = n % r;
            n /= r;
        }
        for(int i = 32 - l; i < 32; i++)
            putchar(num[i] + (num[i]< 10?48:55));
        printf("\n");
    }
}