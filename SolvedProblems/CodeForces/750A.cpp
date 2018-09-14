#include<cstdio>

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    k = 240 - k;
    if(k < 5)
    {
        printf("0");
        return 0;
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        k -= i * 5;
        cnt++;
        if(k < 5 * (i + 1))
            break;
    }
    printf("%d", cnt);
    return 0;
}