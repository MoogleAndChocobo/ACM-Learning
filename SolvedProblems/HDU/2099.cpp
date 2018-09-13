#include <stdio.h>

int main()
{
    int m, n;
    while(~scanf("%d%d", &m, &n))
    {
        if(m == 0 && n == 0)
            break;
        int s[100] = {0};
        m *= 100;
        int count = 0;
        for(int i = 0; i < 100; i++)
        {
            if((m + i) % n == 0)
            {
                s[count] = i;
                count++;
            }
        }
        for(int i = 0; i < count; i++)
        {
            if(s[i] >= 0 && s[i] <= 9)
                printf("0");
            printf("%d", s[i]);
            if(i == count - 1)
                printf("\n");
            else
                printf(" ");
        }
    }
}