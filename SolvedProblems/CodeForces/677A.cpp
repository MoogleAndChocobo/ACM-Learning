#include<cstdio>

int main()
{
    int num, judge;
    scanf("%d%d", &num, &judge);
    int ans = 0;
    for(int i = 0; i < num; i++)
    {
        int temp;
        scanf("%d", &temp);
        if(temp <= judge)
            ans += 1;
        else
            ans += 2;
    }
    printf("%d", ans);
    return 0;
}