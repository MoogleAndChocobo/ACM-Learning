#include<cstdio>
#include<cstring>

int main()
{
    char s[105] = {0};
    char s1[105] = {0};
    char ans[105] = {0};
    scanf("%s%s", s, s1);
    for(int i = 0; i < strlen(s); i++)
        if(s[i] == s1[i])
            ans[i] = '0';
        else
            ans[i] = '1';
    printf("%s\n", ans);
    return 0;
}