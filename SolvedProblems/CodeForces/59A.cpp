#include<cstdio>
#include<cstring>
#include<cctype>

const int MAX = 105;

int main()
{
    char s[MAX] = {0};
    scanf("%s", s);
    int numupper, numlower;
    numupper = numlower = 0;
    for(int i = 0; i < strlen(s); i++)
    {
        if(isupper(s[i]))
            numupper++;
        else
            numlower++;
    }
    if(numupper > numlower)
    {
        for(int i = 0; i < strlen(s); i++)
            s[i] = toupper(s[i]);
    }
    else
    {
        for(int i = 0; i < strlen(s); i++)
            s[i] = tolower(s[i]);
    }
    printf("%s", s);
    return 0;
}