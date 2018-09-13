#include <stdio.h>

int main()
{
    int num, input;
    while(~scanf("%d%d", &num, &input))
    {
        if(num == 0 && input == 0)
            break;
        int s[100] = {0};
        for(int i = 0; i < num; i++)
            scanf("%d", &s[i]);
        int judge = 0;
        for(int i = 0; i < num; i++)
        {
            if(judge == 1)
            {
                printf("%d", s[i]);
            }
            if(input > s[i] && judge == 0)
            {
                printf("%d", s[i]);
            }
            if(input <= s[i] && judge == 0)
            {
                printf("%d", input);
                i--;
                judge = 1;
            }
            if(i != num - 1)
                printf(" ");
        }
        if(judge == 0)
        {
            if(num != 0)
                printf(" ");
            printf("%d\n", input);
        }
        else
            printf("\n");
    }
}