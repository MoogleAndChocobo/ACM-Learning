#include<cstdio>
#include<cstring>
#include<cctype>

int main()
{
    char s[105] = {0};
    scanf("%s", s);
    int len = strlen(s);
    bool flag = true;
    for(int i = 1; i < len; i++)
    {
        if(!isupper(s[i]))
        {
            flag = false;
            break;
        }
    }
    if(flag)
    {
        if(islower(s[0]))
            s[0] = toupper(s[0]);
        else
            s[0] = tolower(s[0]);
        for(int i = 1; i < len; i++)
            s[i] = tolower(s[i]);
    }
    printf("%s\n", s);
    return 0;
}