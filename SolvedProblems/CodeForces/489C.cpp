#include<cstdio>

const int MAX = 110;

int main()
{
    int len, sum;
    scanf("%d%d", &len, &sum);
    if(len == 1 && sum == 0)
    {
        printf("0 0");
        return 0;
    }
    int s1[MAX] = {0};
    int sum2 = sum;
    if(sum < 1 || sum > len * 9)
    {
        printf("-1 -1");
        return 0;
    }
    sum--;
    for(int i = 0; i < len - 1; i++)
    {
        if(sum > 9)
        {
            s1[i] = 9;
            sum -= 9;
        }
        else
        {
            s1[i] = sum;
            sum = 0;
            break;
        }
    }
    if(sum == 0)
        s1[len - 1] = 1;
    else
        s1[len - 1] = sum + 1;
    int s2[MAX] = {0};
    for(int i = 0; i < len; i++)
    {
        if(sum2 >= 9)
        {
            s2[i] = 9;
            sum2 -= 9;
        }
        else
        {
            s2[i] = sum2;
            sum2  = 0;
            break;
        }
    }

    for(int i = len - 1; i >= 0; i--)
        printf("%d", s1[i]);
    printf(" ");
    for(int i = 0; i < len; i++)
        printf("%d", s2[i]);
    return 0;
}