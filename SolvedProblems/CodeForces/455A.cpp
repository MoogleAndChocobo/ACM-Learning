#include<cstdio>
#include<algorithm>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)

typedef long long LL;

const int MAX = 1e5 + 10;

int main()
{
    LL n;
    while(~scanf("%lld", &n))
    {
        LL s[MAX] = {0};
        FOR(i, 0, n - 1)
        {
            LL temp;
            scanf("%lld", &temp);
            s[temp]++;
        }
        LL p = 0, q = 0;
        FOR(i, 1, 1e5)
        {
            LL temp = q + i * s[i];
            q = max(p, q);
            p = temp;
        }
        printf("%lld\n", max(p, q));
    }
    return 0;
}