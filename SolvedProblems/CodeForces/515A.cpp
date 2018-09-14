#include<cstdio>
#include<cmath>

int main()
{
    int a, b, step;
    scanf("%d%d%d", &a, &b, &step);
    int mn = fabs(a) + fabs(b);
    if(step < mn || (step - mn) % 2)
        printf("No\n");
    else
        printf("Yes\n");
    return 0;
}