#include<cstdio>
#include<cstring>

const int MAX = 15;
char s[MAX] = {0};

int main()
{
    scanf("%s", s);
    bool flag = true;
    int len = strlen(s);
    for(int i = 0; i < len;)
    {
        if(i == len - 1 && s[i] == '1')
            break;
        if(i == len - 2)
        {
            if(s[i] == '1' && s[i + 1] == '4')
                break;
            else if(s[i] == '1')
                i++;
        }
        if(s[i] == '1' && s[i + 1] == '4' && s[i + 2] == '4')
            i += 3;
        else if(s[i] == '1' && s[i + 1] == '4')
            i += 2;
        else if(s[i] == '1')
            i++;
        else
        {
            flag = false;
            break;
        }
    }
    if(flag)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}