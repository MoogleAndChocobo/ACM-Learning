#include<cstdio>
#include<cstring>
#include<cctype>

int main()
{
    char s1[110] = {0};
    char s2[110] = {0};
    scanf("%s%s", s1, s2);
    for(int i = 0; i < strlen(s1); i++)
    {
        s1[i] = tolower(s1[i]);
        s2[i] = tolower(s2[i]);
        if(s1[i] == s2[i])
            continue;
        else if(s1[i] > s2[i])
        {
            printf("1");
            return 0;
        }
        else
        {
            printf("-1");
            return 0;
        }
    }
    printf("0");
    return 0;
}