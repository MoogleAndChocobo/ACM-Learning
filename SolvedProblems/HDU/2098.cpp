#include <stdio.h>
#include <math.h>

int judge(int n);

int main()
{
    int num;
    while(~scanf("%d", &num))
    {
        if(num == 0)
            break;
            int count = 0;
        for(int i = 2; i < num / 2; i++)
        {
            int temp = num - i;
            if(judge(i) == 1 && judge(num - i) == 1)
                count++;
        }
        printf("%d\n", count);
    }
}

int judge(int n)
{
    if(n < 2)
        return 0;
    int flag = 1;
    double p = sqrt((double)n);
    for(int i = 2; i <= p; i++)
    {
        if(n % i == 0)
        {
            if(n % i == 0)
            {
                flag = 0;
                break;
            }
        }
    }
    if(flag)
        return 1;
    else
        return 0;
}