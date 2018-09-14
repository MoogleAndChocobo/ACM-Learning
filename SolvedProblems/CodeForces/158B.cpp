#include<cstdio>

int main()
{
    int n, temp;
    scanf("%d", &n);
    int sum, count1, count2, count3;
    sum = count1 = count2 = count3 = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        if(temp == 4)
            sum++;
        else if(temp == 1)
            count1++;
        else if(temp == 2)
            count2++;
        else
            count3++;
    }
    sum += count2 / 2;
    count2 %= 2;
    if(count1 > count3)
    {
        sum += count3;
        count1 -= count3;
        count3 = 0;
    }
    else if(count1 < count3)
    {
        sum += count3;
        count1 = count3 = 0;
    }
    else
    {
        sum += count1;
        count1 = count3 = 0;
    }
    if(count2 == 1 && count1 <= 2)
        sum++;
    else if(count2 == 1 && count1 > 2)
    {
        sum += 1 + (count1 - 2) / 4;
        if((count1 - 2) % 4)
            sum++;
    }
    else if(count2 == 0)
    {
        sum += count1 / 4;
        if(count1 % 4)
            sum++;
    }
    printf("%d\n", sum);
    return 0;
}