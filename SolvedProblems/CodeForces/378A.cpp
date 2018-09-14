#include<cstdio>
#include<cmath>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int cnt1, cnt2, cnt3;
    cnt1 = cnt2 = cnt3 = 0;
    for(int i = 1; i <= 6; i++)
    {
        if(fabs(a - i) < fabs(b - i))
            cnt1++;
        else if(fabs(a - i) == fabs(b - i))
            cnt2++;
        else
            cnt3++;
    }
    printf("%d %d %d\n", cnt1, cnt2, cnt3);
    return 0;
}