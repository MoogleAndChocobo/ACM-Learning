#include <stdio.h>

int main()
{
    int m, n;
    int i, j;
    while(~scanf("%d%d", &m, &n))
    {
        int temp;
        int max_true = 0, max_false = 0, max1 = 0, max2 = 0;
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                scanf("%d", &temp);
                int temp1 = (temp > 0)? temp: -temp;
                if(temp1 > max_false)
                {
                    max_true = temp;
                    max_false = temp1;
                    max1 = i;
                    max2 = j;
                }
            }
        }
        printf("%d %d %d\n", max1 + 1, max2 + 1, max_true);
    }
}