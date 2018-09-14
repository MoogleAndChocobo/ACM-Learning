//Codeforces Boom

#include<cstdio>

int main()
{
    int st, times, n;
    while(~scanf("%d%d%d", &st, &times, &n))
    {
        if((n - st >= 0 && (n - st) % times == 0) || (n - st - 1 > 0 && (n - st - 1) % times == 0))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}