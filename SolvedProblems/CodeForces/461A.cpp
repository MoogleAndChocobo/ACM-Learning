#include<bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)

typedef long long LL;

const int MAXN = 3 * 1e5 + 10;

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        LL s[MAXN] = {0};
        FOR(i, 0, n - 1)
            scanf("%lld", &s[i]);
        sort(s, s + n);
        if(n == 1)
            printf("%lld\n", s[0]);
        else
        {
            LL sum = (s[n - 1] + s[n - 2]) * n;
            for(LL i = 0, j = 2; j < n; i++, j++)
                sum += s[i] * j;
            printf("%lld\n", sum);
        }
    }
    return 0;
}