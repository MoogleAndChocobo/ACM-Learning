#include<cstdio>

const int MAX = 200;

int main()
{
    int n;
    scanf("%d", &n);
    int s[MAX] = {0};
    for(int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    if(s[n - 1] == 15)
        printf("DOWN");
    else if(s[n - 1] == 0)
        printf("UP");
    else if(n == 1)
            printf("-1");
    else if(s[n - 2] < s[n - 1])
            printf("UP");
    else if(s[n - 2] > s[n - 1])
            printf("DOWN");
    return 0;
}