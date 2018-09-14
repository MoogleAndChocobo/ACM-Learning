#include<cstdio>
#include<cstring>

#define ROF(i, a, b) for(int i = a; i >= b; i--)
#define PNT putchar('\n')

const int MAX = 1e6 + 10;

int main()
{
    char s[MAX];
    while(~scanf("%s", s))
    {
        printf("%s");
        int len = strlen(s);
        ROF(i, len - 1, 0)
            printf("%c", s[i]);
        PNT;
    }
    return 0;
}