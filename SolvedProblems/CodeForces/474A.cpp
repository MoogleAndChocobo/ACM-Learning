#include<cstdio>
#include<cstring>

const int MAX = 105;
const char arr[50] = "qwertyuiopasdfghjkl;zxcvbnm,./";

int main()
{
    char judge;
    scanf("%c", &judge);
    getchar();
    char s[MAX] = {0};
    scanf("%s", s);
    if(judge == 'R')
    {
        for(int i = 0; i < strlen(s); i++)
        {
            for(int j = 0; j < strlen(arr); j++)
                if(s[i] == arr[j])
                {
                    s[i] = arr[j - 1];
                    break;
                }
        }
    }
    else if(judge == 'L')
    {
        for(int i = 0; i < strlen(s); i++)
        {
            for(int j = 0; j < strlen(arr); j++)
            {
                if(s[i] == arr[j])
                {
                    s[i] = arr[j + 1];
                    break;
                }
            }
        }
    }
    printf("%s", s);
    return 0;
}