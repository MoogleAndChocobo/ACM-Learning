#include <stdio.h>
#include <string.h>

int main()
{
    int num;
    while(~scanf("%d", &num))
    {
        getchar();
        for(int i = 0; i < num; i++)
        {
            char s[1000];
            gets(s);
            int judge = 0;
            for(int j = 0; j < strlen(s) / 2 + 1; j++)
            {
                if(s[j] != s[strlen(s) - j - 1])
                {
                    judge = 0;
                    break;
                }
                judge = 1;
            }
            if(judge == 0)
                printf("no\n");
            else
                printf("yes\n");
        }
    }
}