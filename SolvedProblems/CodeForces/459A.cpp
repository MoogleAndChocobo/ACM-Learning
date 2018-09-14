#include<cstdio>
#include<cmath>

int main()
{
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    if(x1 == x2 && y1 != y2)
    {
        int a = fabs(y1 - y2);
        printf("%d %d %d %d", x1 + a, y1, x2 + a, y2);
    }
    else if(x1 != x2 && y1 == y2)
    {
        int a = fabs(x1 - x2);
        printf("%d %d %d %d", x1, y1 + a, x2, y2 + a);
    }
    else if(x1 != x2 && y1 != y2)
    {
        int a1, a2, a;
        a1 = fabs(x1 - x2);
        a2 = fabs(y1 - y2);
        if(a1 != a2)
        {
            printf("-1");
            return 0;
        }
        a = a1;
        int x3, y3, x4, y4;
        x3 = x1;
        y3 = y2;
        x4 = x2;
        y4 = y1;
        printf("%d %d %d %d", x3, y3, x4, y4);
    }
    else
        printf("-1");
    return 0;
}