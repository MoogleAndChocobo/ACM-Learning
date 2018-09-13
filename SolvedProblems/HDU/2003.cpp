#include <stdio.h>

int main()
{
    double n;
    while(~scanf("%lf", &n))
    {
        printf("%.2lf\n", (n > 0) ? n : - n);
    }
}