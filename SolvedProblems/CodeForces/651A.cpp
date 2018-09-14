#include<cstdio>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int cnt = 0;
    while(a != 0 && b != 0 && (a > 1 || b > 1))
    {
        if(a > b)
            a -= 2, b++;
        else
            b -= 2, a++;
        cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}