#include<cstdio>

const int MAX = 105;

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    char c;
    int s[MAX] = {0};
    int j = 0;
    while(scanf("%c", &c) && c != '\n')
    {
        if(c == 'B')
            s[j]++;
        else if(s[j] != 0)
            j++;
    }
    int len = 0;
    for(int i = 0; i < MAX; i++)
        if(s[i] != 0)
            len++;
    printf("%d", len);
    if(len != 0)
        printf("\n");
    for(int i = 0; i < len; i++)
    {
        printf("%d", s[i]);
        if(i != len - 1)
            printf(" ");
    }
    return 0;
}