#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int cnt2, cnt3, cnt5, cnt6;
    cnt2 = cnt3 = cnt5 = cnt6 = 0;
    scanf("%d%d%d%d", &cnt2, &cnt3, &cnt5, &cnt6);
    int mn = min(cnt2, cnt5);
    mn = min(mn, cnt6);
    int sum = 256 * mn;
    cnt2 -= mn, cnt5 -= mn, cnt6 -= mn;
    mn = min(cnt2, cnt3);
    sum += mn * 32;
    printf("%d\n", sum);
    return 0;
}