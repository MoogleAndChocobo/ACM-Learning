#include<cstdio>
#include<cstring>

const int MAX = 25;

int main()
{
    char s[MAX] = {0};
    scanf("%s", s);
    int cnt = 0;
    for(int i = 0; i < strlen(s); i++)
        if(s[i] == '4' || s[i] == '7')
            cnt++;
    if(cnt == 4 || cnt == 7)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}