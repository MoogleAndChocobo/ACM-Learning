#include<cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    int cnt = 1, mx = 0, temp, temp1;
    scanf("%d", &temp);
    for(int i = 1; i <= n; i++)
    {
        if(i == n)
            temp1 = 0;
        else
            scanf("%d", &temp1);

        if(temp <= temp1)
            cnt++;
        else
        {
            if(cnt > mx)
                mx = cnt;
            cnt = 1;
        }
        temp = temp1;
    }
    printf("%d\n", mx);
    return 0;
}