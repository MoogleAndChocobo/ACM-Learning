#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    {
        int count;
        scanf("%d", &count);
        double temp;
        double max = 0;
        for(int j = 0; j < count; j++)
        {
            scanf("%lf", &temp);
            if(max < temp)
                max = temp;
        }
        printf("%.2lf\n", max);
    }
}