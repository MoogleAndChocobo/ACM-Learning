#include<cstdio>
#include<cstring>
#include<cctype>

using namespace std;

int main()
{
    char s1[110] = {0};
    char s2[250] = {0};
    scanf("%s", s1);
    for(int i = 0, j = 0; i < strlen(s1); i++)
    {
        if(isalpha(s1[i]))
            s1[i] = towlower(s1[i]);
        if(s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u' || s1[i] == 'y')
            continue;
        else
        {
            s2[j++] = '.';
            s2[j++] = s1[i];
        }
    }
    printf("%s\n", s2);
}