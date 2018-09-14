#include<cstdio>

int main()
{
    int n, times;
    int cnt = 0;
    scanf("%d%d", &n, &times);
    for(int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        if(5 - temp >= times)
            cnt++;
    }
    printf("%d", cnt / 3);
    return 0;
}