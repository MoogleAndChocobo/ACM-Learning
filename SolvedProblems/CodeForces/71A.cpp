#include<cstdio>
#include<cstring>

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        char s[110] = {0};
        scanf("%s", s);
        int len = strlen(s);
        if(len <= 10)
            printf("%s\n", s);
        else
            printf("%c%d%c\n", s[0], len - 2, s[len - 1]);
    }
    return 0;
}