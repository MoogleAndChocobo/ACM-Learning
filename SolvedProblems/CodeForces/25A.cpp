#include<cstdio>

const int MAX = 105;

int main()
{
    int n;
    scanf("%d", &n);
    int cnt0, cnt1;
    cnt0 = cnt1 = 0;
    int s[MAX] = {0};
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
        if(s[i] % 2)
            cnt1++;
        else
            cnt0++;
    }
    if(cnt1 > cnt0)
    {
        for(int i = 0; i < n; i++)
        {
            if(s[i] % 2 == 0)
            {
                printf("%d", i + 1);
                break;
            }
        }
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(s[i] % 2)
            {
                printf("%d", i + 1);
                break;
            }
        }
    }
    return 0;
}