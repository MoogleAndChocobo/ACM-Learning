#include<cstdio>

int main()
{
    int sum, m;
    scanf("%d%d", &sum, &m);
    if(m > sum)
    {
        printf("-1");
        return 0;
    }
    int step = 0;
    if(sum % 2)
        step = sum / 2 + 1;
    else
        step = sum / 2;
    while(step % m)
        step++;
    if(step == 0)
        printf("-1");
    else
        printf("%d", step);
    return 0;
}