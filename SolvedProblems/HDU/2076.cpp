#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const double PI = acos(-1);

int main()
{
    int num = 0;
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    {
        double h, m, s;
        scanf("%lf%lf%lf", &h, &m, &s);
        if (h >= 12)
            h -= 12;
        double ans = fabs(30 * (h + m / 60 + s / 3600) - 6 * (m + s / 60));
        ans = min(ans, 360 - ans);
        if((int)(ans * 10) % 10 >= 5)
            ans--;
        printf("%.f\n", ans);
    }
    return 0;
}