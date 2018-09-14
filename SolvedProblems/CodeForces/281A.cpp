#include<cstdio>
#include<cctype>

int main()
{
    char s[1010] = {0};
    scanf("%s", s);
    s[0] = toupper(s[0]);
    printf("%s", s);
    return 0;
}