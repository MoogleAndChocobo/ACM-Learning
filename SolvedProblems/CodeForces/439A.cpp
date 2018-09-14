#include<cstdio>

int main()
{
    int n, d, temp;
    scanf("%d%d", &n, &d);
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        sum += temp;
        if(i != n - 1)
            sum += 10;
        if(sum > d)
        {
            printf("-1\n");
            return 0;
        }
    }
    int cnt = 2 * (n - 1) + (d - sum) / 5;
    printf("%d\n", cnt);
    return 0;
}