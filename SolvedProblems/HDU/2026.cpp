#include <stdio.h>
#include <string.h>

int main()
{
    char s[100000] = {0};
    while(gets(s) != NULL)
    {
        if(s[0] >= 'a' && s[0] <= 'z')
            s[0] -= 32;
        for(int i = 0; i < strlen(s); i++)
        {
            if(s[i] == ' ')
            {
                if(s[i + 1] >= 'a' && s[i + 1] <= 'z')
                    s[i + 1] -= 32;
            }
        }
        printf("%s\n", s);
    }
}