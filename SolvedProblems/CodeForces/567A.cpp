#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

int s[100010] = {0};

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    int mx, mn;
    mn = mx = s[0];
    for(int i = 1; i < n; i++)
    {
        mx = max(mx, s[i]);
        mn = min(mn, s[i]);
    }
    for(int i = 0; i < n; i++)
    {
        int a = fabs(mx - s[i]);
        int b = fabs(mn - s[i]);
        int tempmax = max(a, b);
        int tempmin;
        if(i == 0)
            tempmin = s[1] - s[0];
        else if(i == n - 1)
            tempmin = s[i] - s[i - 1];
        else
            tempmin = min(s[i] - s[i - 1], s[i + 1] - s[i]);
        printf("%d %d\n", tempmin, tempmax);
    }
    return 0;
}