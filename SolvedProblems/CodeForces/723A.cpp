#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int mn = fabs(a - b) + fabs(a - c);
    int temp = fabs(a - b) + fabs(b - c);
    mn = min(mn, temp);
    temp = fabs(a - c) + fabs(b - c);
    mn = min(mn, temp);
    printf("%d\n", mn);
    return 0;
}