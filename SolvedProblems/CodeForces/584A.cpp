#include<cstdio>

int main()
{
    int len, n;
    scanf("%d%d", &len, &n);
    if(len == 1)
    {
        if(n == 10)
        {
            printf("-1");
            return 0;
        }
        printf("%d", n);
    }
    else
    {
        if(n == 10)
        {
            for(int i = 0; i < len - 2; i++)
                printf("1");
            printf("10");
            return 0;
        }
        else
        {
            for(int i = 0; i < len; i++)
                printf("%d", n);
        }
    }
    return 0;
}