#include<bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)

const int MAX = 5 * 1e4 + 10;

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        pair<int, int> s[MAX];
        FOR(i, 0, n - 1)
            scanf("%d%d", &s[i].first, &s[i].second);
        sort(s, s + n);
        int ans = s[0].second;
        FOR(i, 0, n - 1)
        {
            if(s[i].second >= ans)
                ans = min(s[i].second, s[i].first);
            else
                ans = s[i].first;
        }
        printf("%d\n", ans);
    }
    return 0;
}