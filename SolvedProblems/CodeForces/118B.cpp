#include<cstdio>

#define PNT putchar('\n')

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        for(int i = 1; i <= n + 1; i++)
        {
            for(int j = 0; j < 2 * (n + 1 - i); j++)
                printf(" ");
            if(i == 1)
                printf("0");
            else
            {
                printf("0 ");
                for(int j = 1; j <= i - 1; j++)
                    printf("%d ", j);
                for(int j = i - 2; j >= 1; j--)
                    printf("%d ", j);
                printf("0");
            }
            PNT;
        }

        for(int i = n; i >= 1; i--)
        {
            for(int j = 0; j < 2 * (n + 1 - i); j++)
                printf(" ");
            if(i == 1)
                printf("0");
            else
            {
                printf("0 ");
                for(int j = 1; j <= i - 1; j++)
                    printf("%d ", j);
                for(int j = i - 2; j >= 1; j--)
                    printf("%d ", j);
                printf("0");
            }
            PNT;
        }
    }
    return 0;
}