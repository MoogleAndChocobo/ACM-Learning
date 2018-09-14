#include<cstdio>
#include<cstring>

const int MAX = 100010;

char s[MAX] = {0};

int main()
{
    scanf("%s", s);
    int len = strlen(s);
    bool find1 = false;
    for(int i = 0; i < len - 1; i++)
    {
        if(find1 == false && s[i] == 'A' && s[i + 1] == 'B')
        {
            find1 = true;
            i++;
            continue;
        }
        if(find1 && s[i] == 'B' && s[i + 1] == 'A')
        {
            printf("YES");
            return 0;
        }
    }
    int find2 = false;
    for(int i = 0; i < len - 1; i++)
    {
        if(find2 == false && s[i] == 'B' && s[i + 1] == 'A')
        {
            find2 = true;
            i++;
            continue;
        }
        if(find2 && s[i] == 'A' && s[i + 1] == 'B')
        {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}