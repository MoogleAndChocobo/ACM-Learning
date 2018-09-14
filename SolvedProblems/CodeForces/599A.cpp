#include<cstdio>

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if(a + b <= c)
        printf("%d", 2 * (a + b));
    else if(a + c <= b)
        printf("%d", 2 * (a + c));
    else if(b + c <= a)
        printf("%d", 2 * (b + c));
    else
        printf("%d", a + b + c);
    return 0;
}