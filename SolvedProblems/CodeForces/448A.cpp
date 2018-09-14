#include<cstdio>

int main()
{
    int cups, medals, temp;
    cups = medals = 0;
    for(int i = 0; i < 3; i++)
    {
        scanf("%d", &temp);
        cups += temp;
    }
    for(int i = 0; i < 3; i++)
    {
        scanf("%d", &temp);
        medals += temp;
    }
    int n;
    scanf("%d", &n);
    int sum1, sum2;
    sum1 = cups / 5;
    if(cups % 5)
        sum1++;
    sum2 = medals / 10;
    if(medals % 10)
        sum2++;
    if(sum1 + sum2 <= n)
        printf("YES");
    else
        printf("NO");
    return 0;
}