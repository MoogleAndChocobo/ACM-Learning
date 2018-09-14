#include<cstdio>

const int MAX = 105;
int s[MAX] = {0};

int main()
{
    int n;
    scanf("%d", &n);
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
        sum += s[i];
    }
    sum /= (n / 2);
    for(int i = 0; i < n - 1; i++)
    {
        if(s[i] == 0)
            continue;
        for(int j = i + 1; j < n; j++)
            if(s[j] + s[i] == sum)
            {
                printf("%d %d\n", i + 1, j + 1);
                s[i] = s[j] = 0;
                break;
            }
    }
    return 0;
}