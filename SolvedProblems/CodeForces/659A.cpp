#include<cstdio>

int main()
{
    int sum, st, step;
    scanf("%d%d%d", &sum, &st, &step);
    st += step;
    while(st <= 0 || st > sum)
        if(st > sum)
            st -= sum;
        else if(st < 1)
            st += sum;
    printf("%d\n", st);
    return 0;
}