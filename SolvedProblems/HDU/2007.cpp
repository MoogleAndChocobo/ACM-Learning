#include <stdio.h>
int main()
{
    int min, max, temp, i;
    while(scanf("%d%d", &min, &max) == 2)
    {
        if (min > max)
        {
            temp = min;
            min = max;
            max = temp;
        }
        int sum1 = 0, sum2 = 0;
        for(i = min; i <= max; i++)
        {
            if(!(i % 2))
                sum1 += i * i;
            if(i % 2)
                sum2 += i * i * i;
        }
        printf("%d %d\n", sum1, sum2);
    }
}