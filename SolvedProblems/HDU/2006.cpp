#include <stdio.h>
int main()
{
    int n, i;
    while(scanf("%d", &n) != EOF)
    {
        int a, product = 1;
        for(i = 0; i < n; i++)
        {
            scanf("%d", &a);
            if (a % 2)
                product *= a;
        }
        printf("%d\n", product);
    }
}