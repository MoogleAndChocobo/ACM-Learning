#include<cstdio>

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    int sum;
    if(m % 2 == 0)
        sum = (m / 2) * n;
    else if(n % 2 == 0)
        sum = (n / 2) * m;
    else
        sum = m * n / 2;
    printf("%d\n", sum);
    return 0;
}