#include <stdio.h>

int main()
{
    int n;
    int s[60] = {0};
    s[1] = 1;
    s[2] = 2;
    s[3] = 3;
    while(~scanf("%d", &n))
    {
        if(n == 0)
            break;
        for(int i = 4; i <= n; i++)
            s[i] = s[i - 1] + s[i - 3];
        printf("%d\n", s[n]);
    }
}