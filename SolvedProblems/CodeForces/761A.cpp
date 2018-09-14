#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
    int n, r;
    while(~scanf("%d%d", &n, &r))
    {
        if((n == r || fabs(n - r) == 1) && !(n == r && n == 0))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}