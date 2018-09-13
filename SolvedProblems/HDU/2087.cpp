#include <stdio.h>
#include <string.h>

int main()
{
    char s1[1001] = {0};
    char s2[1001] = {0};
    int i, j;
    while(~scanf("%s", s1))
    {
        if(s1[0] == '#')
            break;
        else
            scanf("%s", s2);
        int count = 0;
        for(i = 0; i <= strlen(s1) - strlen(s2); i++)
        {
            if(s1[i] == s2[0])
            {
                if(strlen(s2) == 1)
                {
                    count++;
                    continue;
                }
                int temp = i;
                for(j = 1; j < strlen(s2); j++)
                {
                    temp++;
                    if(s1[temp] != s2[j])
                        break;
                    if(j == strlen(s2) - 1)
                    {
                        count++;
                        i += strlen(s2) - 1;
                    }
                }
            }
        }
        printf("%d\n", count);
    }
}