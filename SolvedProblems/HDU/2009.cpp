#include <stdio.h>
#include <math.h> 
int main()
{
    int n, m, i;
    while(scanf("%d%d", &n, &m) == 2)
    {
        if(m >= 0 && n >= 0)
        {
            double sum = 0;
            sum += n;
            double p = n;
            for(i = 1; i < m; i++)
            {
                p = sqrt(p);
                sum += p;
            }
            printf("%.2lf\n", sum);
        }
    }
}