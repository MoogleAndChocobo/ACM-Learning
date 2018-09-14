#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int mx = -1;
    mx = max(mx, a + b + c);
    mx = max(mx, a + b * c);
    mx = max(mx, a * b + c);
    mx = max(mx, a * b * c);
    mx = max(mx, (a + b) * c);
    mx = max(mx, a * (b + c));
    printf("%d\n", mx);
    return 0;
}