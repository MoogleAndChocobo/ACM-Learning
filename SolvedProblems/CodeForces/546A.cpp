#include<cstdio>

int main()
{
    int k, own, n;
    scanf("%d%d%d", &k, &own, &n);
    int sum = (1 + n) * n / 2 * k;
    if(sum <= own)
        printf("0\n");
    else
        printf("%d\n", sum - own);
    return 0;
}