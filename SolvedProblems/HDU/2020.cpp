#include <stdio.h>

int main()
{
    int num;
    while(~scanf("%d", &num))
    {
        if(num == 0)
            break;
        int s[100] = {0};
        int s0[100] = {0};
        for(int i = 0; i < num; i++)
        {
            scanf("%d", &s[i]);
            s0[i] = (s[i] > 0)? s[i] : -s[i];
        }
        for(int i = 0; i < num; i++)
        {
            for(int j = 1; j < num - i; j++)
            {
                if(s0[j] > s0[j - 1])
                {
                    int temp = s0[j];
                    s0[j] = s0[j - 1];
                    s0[j - 1] = temp;
                    temp = s[j];
                    s[j] = s[j - 1];
                    s[j - 1] = temp;
                }
            }
        }
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