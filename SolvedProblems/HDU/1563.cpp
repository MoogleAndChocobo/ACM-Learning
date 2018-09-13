#include <stdio.h>

int main()
{
    int num;
    int s[200] = {0};
    while(~scanf("%d", &num))
    {
        if(num == 0)
            break;
        for(int i = 0; i < num; i++)
            scanf("%d", &s[i]);
        int judge = -1;
        for(int i = 0; i < num; i++)
        {
            for(int j = 0; j < num; j++)
            {
                if(s[i] == s[j] && i != j)
                    break;
                if(j == num - 1)
                {
                    judge = s[i];
                    break;
                }
            }
            if(judge != -1)
            {
                printf("%d\n", judge);
                break;
            }
        }
    }
}