#include<cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    int cnt = 0;
    int mn, mx, temp;
    scanf("%d", &temp);
    mx = mn = temp;
    for(int i = 1; i < n; i++)
    {
        scanf("%d", &temp);
        if(mx < temp)
        {
            cnt++;
            mx = temp;
        }
        if(mn > temp)
        {
            cnt++;
            mn  = temp;
        }
    }
    printf("%d\n", cnt);
    return 0;
}