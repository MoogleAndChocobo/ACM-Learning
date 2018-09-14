#include<bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)

const int MAX = 1e5 + 10;

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        int a[MAX] = {0};
        int ans[MAX] = {0};
        FOR(i, 1, n)
            scanf("%d", &a[i]);
        set<int> judge;
        ROF(i, n, 1)
        {
            judge.insert(a[i]);
            ans[i] = judge.size();
        }
        while(m--)
        {
            int now;
            scanf("%d", &now);
            printf("%d\n", ans[now]);
        }
    }
    return 0;
}