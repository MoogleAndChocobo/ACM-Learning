#include<stdio.h>

int main()
{
    int sminTime[50];
    int smaxTime[50];
    int d, sumTime;
    scanf("%d%d", &d, &sumTime);
    {
        for(int i = 0; i < d; i++)
            scanf("%d%d", &sminTime[i], &smaxTime[i]);
        int sum = 0;
        int sum1 = 0;
        for(int i = 0; i < d; i++)
        {
            sum += smaxTime[i];
            sum1 += sminTime[i];
        }
        if(sum < sumTime || sum1 > sumTime)
            printf("NO");
        else
        {
            printf("YES\n");
            int time = sum - sumTime;
            for(int i = 0; i < d; i++)
            {
                for(int j = time; j >= 0; j--)
                {
                    if(smaxTime[i] - j >=  sminTime[i])
                    {
                        printf("%d", smaxTime[i] - j);
                        time -= j;
                        break;
                    }
                }
                if(i != d - 1)
                    printf(" ");
            }
        }
    }
    return 0;
}