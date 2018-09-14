#include<cstdio>

int main()
{
    int n, x = 0;
    scanf("%d", &n);
    getchar();
    char s[5] = {0};
    for(int i = 0; i < n; i++)
    {
        scanf("%s", s);
        if(s[1] == '+')
            x++;
        else if(s[1] == '-')
            x--;
    }
    printf("%d\n", x);
    return 0;
}