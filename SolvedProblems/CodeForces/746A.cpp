#include<cstdio>

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if(a <= c / 4 && a <= b / 2)
        printf("%d\n", 7 * a);
    else if(b / 2 <= c / 4 && b / 2 <= a)
        printf("%d\n", b / 2 * 7);
    else
        printf("%d\n", c / 4 * 7);
    return 0;
}