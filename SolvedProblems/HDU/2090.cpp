#include <stdio.h>

int main()
{
    char s[100] = {0};
    double sum = 0;
    while(~scanf("%s", s))
    {
        double num, price;
        scanf("%lf%lf", &num, &price);
        sum += num * price;
    }
    printf("%.1lf\n", sum);
}