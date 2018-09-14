#include<cstdio>
#include<cstring>
#include<cctype>

int main()
{
    char s[15] = {0};
    scanf("%s", s);
    int len = strlen(s);
    if(isdigit(s[0]))
        printf("%s", s);
    else
    {
        if(s[len - 1] > s[len - 2])
            s[len - 1] = '\0';
        else
        {
            s[len - 2] = s[len - 1];
            s[len - 1] = '\0';
        }
        if(len == 3 && s[1] == '0')
           printf("0\n");
        else
            printf("%s\n", s);
    }
    return 0;
}