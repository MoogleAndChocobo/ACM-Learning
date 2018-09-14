#include<cstdio>

const int MAX = 25;

int main()
{
    int n;
    scanf("%d", &n);
    char s[MAX] = {0};
    int sum = 0;
    while(n--)
    {
        scanf("%s", s);
        if(s[0] == 'T')
            sum += 4;
        else if(s[0] == 'C')
            sum += 6;
        else if(s[0] == 'O')
            sum += 8;
        else if(s[0] == 'D')
            sum += 12;
        else if(s[0] == 'I')
            sum += 20;
    }
    printf("%d", sum);
    return 0;
}