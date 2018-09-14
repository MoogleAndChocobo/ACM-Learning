#include<cstdio>
#include<algorithm>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)

const int INF = 0xfffffff;
const int MAXN = 1e5 + 10;

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        int s[MAXN] = {0};
        int pre, now;
        scanf("%d", &pre);
        int mx = 0;
        FOR(i, 0, n - 2)
        {
            scanf("%d", &now);
            s[i] = now - pre;
            pre = now;
            mx = max(s[i], mx);
        }
        int mn = INF;
        FOR(i, 1, n - 2)
        {
            int tempmx = max(mx, s[i] + s[i - 1]);
            mn = min(mn, tempmx);
        }
        printf("%d\n", mn);
    }
    return 0;
}