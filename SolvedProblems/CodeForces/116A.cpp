#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int sum, mx;
    sum = mx = 0;
    while(n--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        sum -= x;
        sum += y;
        mx = max(mx, sum);
    }
    printf("%d\n", mx);
    return 0;
}