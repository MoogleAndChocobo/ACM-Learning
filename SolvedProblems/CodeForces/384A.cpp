#include<cstdio>
#include<cmath>

#define FOR(i, a, b) for(int i = a; i <= b; i++)

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        int sum;
        if(n % 2 == 0)
            sum = (n / 2) * n;
        else
            sum = (n / 2) * n + n / 2 + 1;
        printf("%d\n", sum);
        if(n % 2 == 0)
        {
            FOR(i, 0, n - 1)
            {
                for(int j = 0; j < n; j++)
                {
                    if(i % 2 == 0)
                    {
                        if(j % 2 == 0)
                            printf("C");
                        else
                            printf(".");
                    }
                    else
                    {
                        if(j % 2 == 0)
                            printf(".");
                        else
                            printf("C");
                    }
                }
                printf("\n");
            }
        }
        else
        {
            FOR(i, 0, n - 1)
            {
                for(int j = 0; j < n; j++)
                {
                    if(i % 2 == 0)
                    {
                        if(j % 2 == 0)
                            printf("C");
                        else
                            printf(".");
                    }
                    else
                    {
                        if(j % 2 == 0)
                            printf(".");
                        else
                            printf("C");
                    }
                }
                printf("\n");
            }
        }
    }
    return 0;
}