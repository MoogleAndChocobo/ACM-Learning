#include<cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    int sum0, sum1, sum2, temp;
    sum0 = sum1 = sum2 = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        sum0 += temp;
    }
    for(int i = 0; i < n - 1; i++)
    {
        scanf("%d", &temp);
        sum1 += temp;
    }
    for(int i = 0; i < n - 2; i++)
    {
        scanf("%d", &temp);
        sum2 += temp;
    }
    printf("%d\n%d", sum0 - sum1, sum1 - sum2);
    return 0;
}