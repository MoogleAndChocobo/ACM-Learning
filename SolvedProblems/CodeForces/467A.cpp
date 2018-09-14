#include<cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if(y - x >= 2)
            cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}