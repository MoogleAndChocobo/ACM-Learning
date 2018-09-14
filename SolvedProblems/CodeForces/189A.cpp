#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)

const int MAX = 4 * 1e3;
const int INF = 0x3f3f3f3f;

int main()
{
    int n;
    int s[MAX] = {0};
    int dp[MAX] = {0};
    while(~scanf("%d", &n))
    {
        FOR(i, 0, 2)
            scanf("%d", &s[i]);
        FOR(i, 1, n)
            dp[i] = -INF;
        dp[0] = 0;
        FOR(i, 0, 2)
            for(int j = s[i]; j <= n; j++)
                dp[j] = max(dp[j], dp[j - s[i]] + 1);
        printf("%d\n", dp[n]);
    }
    return 0;
}