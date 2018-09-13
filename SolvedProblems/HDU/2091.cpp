#include <stdio.h>

int main()
{
    char c;
    int num;
    int i, j, k;
    int judge = 0;
    while(~scanf("%c", &c))
    {
        if(c == '@')
            break;
        if(judge == 1)
            printf("\n");        
        scanf("%d", &num);
        getchar();
        for(i = 1; i <= num; i++)
        {
            for(j = 0; j < num - i; j++)
                printf(" ");
            if(i == 1)
            {
                printf("%c\n", c);
                continue;
            }
            if(i == num)
            {
                for(j = 0; j < 2 * num - 1; j++)
                {
                    printf("%c", c);
                    if(j == 2 * num - 2)
                        printf("\n");
                }
            }else{
                printf("%c", c);
                for(j = 0; j < 2 * i - 3; j++)
                    printf(" ");
                printf("%c\n", c);
            }
        }
        judge = 1;
    }
}