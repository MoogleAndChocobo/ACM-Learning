#include<cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    if(n % 2 == 0)
    {
        printf("%d\n", n / 2);
        for(int i = 0; i < n / 2; i++)
        {
            printf("2");
            if(i != n / 2 - 1)
                printf(" ");
        }
        printf("\n");
    }
    else
    {
        printf("%d\n", n / 2);
        for(int i = 0; i < n / 2 - 1; i++)
            printf("2 ");
        printf("3\n");
    }
    return 0;
}