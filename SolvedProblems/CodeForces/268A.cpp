#include<cstdio>

const int MAX = 35;

int main()
{
    int n;
    scanf("%d", &n);
    int home[MAX] = {0};
    int guest[MAX] = {0};
    for(int i = 0; i < n; i++)
        scanf("%d%d", &home[i], &guest[i]);
    int cnt = 0;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(home[i] == guest[j])
                cnt++;
            if(home[j] == guest[i])
                cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}