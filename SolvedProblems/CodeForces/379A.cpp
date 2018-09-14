#include<cstdio>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int sum = n;
    while(n >= m)
    {
        sum += n / m;
        n = n / m + n % m;
    }
    printf("%d\n", sum);
    return 0;
}