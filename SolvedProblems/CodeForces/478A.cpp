#include<cstdio>

int main()
{
    int a, b, c, d, e;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    int sum = a + b + c + d + e;
    if(sum % 5 || sum == 0)
        printf("-1");
    else
        printf("%d", sum / 5);
    return 0;
}