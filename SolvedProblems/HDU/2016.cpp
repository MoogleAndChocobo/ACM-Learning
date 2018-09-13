#include <stdio.h>

int main()
{
    int num;
    while(~scanf("%d", &num))
    {
        if(num == 0)
            break;
        int s[100] = {0};
        for(int i = 0; i < num; i++)
            scanf("%d", &s[i]);
        int min = s[0];
        int count = 0;
        for(int i = 1; i < num; i++)
        {
            if(min > s[i])
            {
                min = s[i];
                count = i;
            }
        }
        int temp = s[0];
        s[0] = s[count];
        s[count] = temp;
        for(int i = 0; i < num; i++)
        {
            printf("%d", s[i]);
            if(i == num - 1)
                printf("\n");
            else
                printf(" ");
        }
    }
}