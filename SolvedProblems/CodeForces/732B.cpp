#include<cstdio>

const int MAX = 510;
int s[MAX] = {0};

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    int sum = 0;
    for(int i = 1; i < n; i++)
        if(s[i] + s[i - 1] < k)
        {
            sum += k - s[i] - s[i - 1];
            s[i] = k - s[i - 1];
        }
    printf("%d\n", sum);
    for(int i = 0; i < n; i++)
    {
        printf("%d", s[i]);
        if(i != n - 1)
            printf(" ");
        else
            printf("\n");
    }
    return 0;
}