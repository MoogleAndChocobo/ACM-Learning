#include <stdio.h>

int main()
{
    int m, n;
    int i, j;
    while(~scanf("%d%d", &m, &n))
    {
        printf("+");
        for(i = 0; i < m; i++)
            printf("-");
        printf("+\n");
        for(i = 0; i < n; i++)
        {
            printf("|");
            for(j = 0; j < m; j++)
                printf(" ");
            printf("|\n");
        }
        printf("+");
        for(i = 0; i < m; i++)
            printf("-");
        printf("+\n");
        printf("\n");
    }
} 