#include<cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    int s[110][3] = {0};
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 3; j++)
            scanf("%d", &s[i][j]);
    bool flag = true;
    for(int i = 0; i < 3; i++)
    {
        int sum = 0;
        for(int j = 0; j < n; j++)
            sum += s[j][i];
        if(sum != 0)
        {
            flag = false;
            break;
        }
    }
    if(flag)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}