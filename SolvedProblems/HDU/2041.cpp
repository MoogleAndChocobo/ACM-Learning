#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    {
        int n;
        scanf("%d", &n);
        int s[40] = {0};
        s[0] = 1;
        s[1] = 2;
        if(n == 1)
        {
            printf("0\n");
            continue;
        }
        if(n == 2)
        {
            printf("1\n");
            continue;
        }
        for(int j = 2; j < n - 1; j++)
            s[j] = s[j - 1] + s[j - 2];
        printf("%d\n", s[n - 2]);
    }
}