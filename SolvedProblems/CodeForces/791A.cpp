#include<cstdio>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int times = 0;
    while(a <= b)
    {
        b *= 2;
        a *= 3;
        times++;
    }
    printf("%d", times);
    return 0;
}