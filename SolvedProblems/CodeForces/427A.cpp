#include<cstdio>

int main()
{
    int num;
    scanf("%d", &num);
    int police = 0, ans = 0;
    for(int i = 0; i < num; i++)
    {
        int temp;
        scanf("%d", &temp);
        if(temp >  0)
            police += temp;
        else if(police >= -temp)
            police += temp;
        else
        {
            police = 0;
            ans -= police + temp;
        }
    }
    printf("%d", ans);
    return 0;
}