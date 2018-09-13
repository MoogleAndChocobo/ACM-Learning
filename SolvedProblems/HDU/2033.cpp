#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    {
        int ah, am, as, bh, bm, bs;
        scanf("%d%d%d%d%d%d", &ah, &am, &as, &bh, &bm, &bs);
        int sum_h, sum_m, sum_s;
        sum_h = ah + bh;
        sum_m = am + bm;
        sum_s = as + bs;
        if(sum_s >= 60)
        {
            sum_m += sum_s / 60;
            sum_s -= sum_s / 60 * 60;
        }
        if(sum_m >= 60)
        {
            sum_h += sum_m / 60;
            sum_m -= sum_m / 60 * 60;
        }
        printf("%d %d %d\n", sum_h, sum_m, sum_s);
    }
}