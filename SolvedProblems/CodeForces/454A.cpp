#include<cstdio>

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define PNT putchar('\n')

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        for(int i = n / 2, cnt = 1; i >= 1; i--, cnt++)
        {
            for(int j = 0; j < i; j++)
                printf("*");
            for(int j = 0; j < 2 * cnt - 1; j++)
                printf("D");
            for(int j = 0; j < i; j++)
                printf("*");
            PNT;
        }
        FOR(i, 1, n)
            printf("D");
        PNT;
        for(int i = 1, cnt = n / 2; i <= n / 2; i++, cnt--)
        {
            for(int j = 0; j < i; j++)
                printf("*");
            for(int j = 0; j < 2 * cnt - 1; j++)
                printf("D");
            for(int j = 0; j < i; j++)
                printf("*");
            PNT;
        }
    }
    return 0;
}