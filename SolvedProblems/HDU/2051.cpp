#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        char s[10] = {0};
        if(n == 0)
        {
            printf("0\n");
            continue;
        }
        int i = 0;
        while(n)
        {
            s[i] = n % 2 + 48;
            n /= 2;
            i++;
        }
        for(i = strlen(s) - 1; i >= 0; i--)
            printf("%c", s[i]);
        printf("\n");
    }
}