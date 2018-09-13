#include <stdio.h>
int main()
{
    int m, n, i;
    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        scanf("%d", &n);
        float sum = 0;
        int j;
        for (j = 1; j <= n; j++)
        {
            if(j % 2 == 0)
                sum -= 1 / (float)j;
            if(j % 2 != 0)
                sum += 1 / (float)j;
        }
        printf("%.2f\n", sum);
    }
}