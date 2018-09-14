#include<cstdio>
#include<algorithm>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)

typedef long long LL;

const int MAX = 2 * 1e3 + 10;
const int INF = 0xffffffff;

int main()
{
    LL n, sum;
    while(~scanf("%lld%lld", &n, &sum))
    {
        LL v, t;
        scanf("%lld%lld", &v, &t);
        LL mx;
        if(t <= sum)
            mx = v;
        else
            mx = v - (t - sum);
        FOR(i, 1, n - 1)
        {
            scanf("%lld%lld", &v, &t);
            if(t <= sum)
                mx = max(v, mx);
            else
                mx = max(v - (t - sum), mx);
        }
        printf("%lld\n", mx);
    }
    return 0;
}