#include <stdio.h>
int main()
{
    int n, i;
    float a;
    while(scanf("%d", &n) != EOF)
    {
        if(n == 0)
            continue;; 
        int num1 = 0, num2 = 0, num3 = 0; 
        for(i = 0; i < n; i++)
        {
            scanf("%f", &a);
            if(a < 0)
                num1++;
            if(a == 0)
                num2++;
            if(a > 0)
                num3++;
        }
        printf("%d %d %d\n", num1, num2, num3);
    }
} 