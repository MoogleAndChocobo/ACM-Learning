#include <stdio.h>
#include <string.h>

int main()
{
    char s[51] = {0};
    int num;
    while(~scanf("%d", &num))
    {
        getchar();
        for(int i = 0; i < num; i++)
        {
            int judge = 0;
            gets(s);
            if(!(s[0] == '_' || (s[0] >= 'a' && s[0] <= 'z') ||(s[0] >= 'A' && s[0] <= 'Z')))
            {
                printf("no\n");
                continue;
            }
            for(int i = 1; i < strlen(s); i++)
            {
                if(!(s[i] == '_' || (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')))
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