#include<cstdio>
#include<cstring>

const int MAX = 25;
char s[MAX] = {0};

int main()
{
    scanf("%s", s);
    if(s[0] >= '5' && s[0] != '9')
        s[0] = 9 - (s[0] - 48) + 48;
    for(int i = 1; i < strlen(s); i++)
    {
        if(s[i] >= '5')
            s[i] = 9 - (s[i] - 48) + 48;
    }
    printf("%s\n", s);
    return 0;
}