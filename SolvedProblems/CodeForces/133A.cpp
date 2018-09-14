#include<cstdio>
#include<cstring>

int main()
{
    char s[110] = {0};
    scanf("%s", s);
    for(int i = 0; i < strlen(s); i++)
    {
        if(s[i] == 'H' || s[i] == 'Q' || s[i] == '9')
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}