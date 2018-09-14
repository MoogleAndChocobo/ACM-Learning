#include<cstdio>
#include<cmath>

#define FOR(i, a, b) for(int i = a; i <= b; i++)

int main()
{
    int n, mx;
    while(~scanf("%d%d", &n, &mx))
    {
        int sum = 0;
        FOR(i, 0, n - 1)
        {
            int temp;
            scanf("%d", &temp);
            sum += temp;
        }
        sum = fabs(sum);
        int ans = sum / mx;
        if(sum % mx)
            ans++;
        printf("%d\n", ans);
    }
    return 0;
}