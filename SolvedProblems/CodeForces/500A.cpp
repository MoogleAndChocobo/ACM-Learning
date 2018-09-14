#include<cstdio>

int s[100010] = {0};

int main()
{
    int n, t;
    scanf("%d%d", &n, &t);
    for(int i = 1; i < n; i++)
        scanf("%d", &s[i]);
    bool flag = false;
    for(int i = 1; i <= t;)
    {
        i += s[i];
        if(i == t)
        {
            flag = true;
            break;
        }
    }
    if(flag)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}