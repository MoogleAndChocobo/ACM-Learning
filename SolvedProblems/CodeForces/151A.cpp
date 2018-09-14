#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int s[10] = {0};
    for(int i = 1; i <= 8; i++)
        scanf("%d", &s[i]);
    int cnt = (s[3] * s[2]) / s[7];
    int cnt1 = min(s[4] * s[5], s[6] / s[8]);
    cnt = min(cnt, cnt1);
    cnt /= s[1];
    printf("%d", cnt);
    return 0;
}