#include<cstdio>
#include<cstring>

int main()
{
    char s[205] = {0};
    char s1[205] = {0};
    scanf("%s", s);
    int len = strlen(s);
    for(int i = len - 1; i >= 2; i--)
    {
        if(s[i] == 'B' && s[i-1] == 'U' && s[i-2] == 'W')
        {
            s[i] == '\0';
            s[i-1] == '\0';
            s[i-2] == '\0';
            i -= 2;
            len -= 3;
        }
        else
            break;
    }
    bool flag = false;
    for(int i = 0, j = 0; i < len; i++)
    {
        if(s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B')
        {
            if(flag)
            {
                s1[j] = ' ';
                j++;
                flag = false;
            }
            i += 2;
        }
        else
        {
            s1[j] = s[i];
            j++;
            flag = true;
        }
    }
    printf("%s", s1);
    return 0;
}