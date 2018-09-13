#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if(a % b)
            printf("NO\n");
        else
            printf("YES\n");
    }
}