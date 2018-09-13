#include <stdio.h>

int main()
{
    int num;
    int i, j;
    while(~scanf("%d", &num))
    {
        double s[100] = {0};
        for(i = 0;i < num; i++)
            scanf("%lf", &s[i]);
        for(i = 0; i < num; i++)
        {
            for(j = 1; j < num - i; j++)
            {
                if(s[j] > s[j - 1])
                {
                    double temp = s[j];
                    s[j] = s[j - 1];
                    s[j - 1] = temp;
                }
            }
        }
        double sum = 0;
        for(i = 1; i < num - 1; i++)
            sum += s[i];
        printf("%.2lf\n", sum / (num - 2));
    }
}