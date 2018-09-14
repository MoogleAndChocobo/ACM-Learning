#include<cstdio>

int main()
{
    int x;
    scanf("%d", &x);
    int sum = x / 5;
    if(x % 5)
        sum++;
    printf("%d\n", sum);
    return 0;
}