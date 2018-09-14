#include<cstdio>

int main()
{
    int sum = 0;
    scanf("%d", &sum);
    int i = 1;
    while(sum >= (1 + i) * i / 2)
    {
        sum -= (1 + i) * i / 2;
        i++;
    }
    printf("%d", i - 1);
    return 0;
}