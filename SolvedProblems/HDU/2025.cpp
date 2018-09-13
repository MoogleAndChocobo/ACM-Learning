#include <stdio.h>
#include <string.h>

int main()
{
    char s[101] = {0};
    while(~scanf("%s", s))
    {
        char max = s[0];
        for(int i = 1; i < strlen(s); i++)
        {
            if(max < s[i])
                max = s[i];
        }
        for(int i = 0; i < strlen(s); i++)
        {
            if(max == s[i])
                printf("%c(max)", s[i]);
            else
                printf("%c", s[i]);
        }
        printf("\n");
    }
}