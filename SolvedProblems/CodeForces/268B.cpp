#include<cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    int sum = n;
    for(int i = n - 1, j = 1; i >= 1; i--, j++)
        sum += i * j;
    printf("%d", sum);
    return 0;
}