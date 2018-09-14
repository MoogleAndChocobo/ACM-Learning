#include<bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)

const int MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        int s[MAX] = {0};
        int mn = INF;
        FOR(i, 0, n - 1)
        {
            scanf("%d", &s[i]);
            mn = min(mn, s[i]);
        }
        int cnt = 0;
        int store[MAX] = {0};
        FOR(i, 0, n - 1)
        {
            if(mn == s[i])
                store[cnt++] = i;
        }
        int mndist = INF;
        FOR(i, 1, cnt - 1)
            mndist = min(mndist, store[i] - store[i - 1]);
        printf("%d\n", mndist);
    }
    return 0;
}