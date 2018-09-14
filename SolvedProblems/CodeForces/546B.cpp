#include<cstdio>
#include<algorithm>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)

const int MAXN = 1e4 + 10;

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        int s[MAXN] = {0};
        int store[MAXN] = {0};
        int sum = 0;
        FOR(i, 0, n - 1)
        {
            scanf("%d", &s[i]);
            store[s[i]]++;
            sum += s[i];
        }
        sort(s, s + n);
        int ans = s[0];
        FOR(i, 1, n)
        {
            if(s[i] == s[i - 1])
            {
                int cnt = s[i] + 1;
                while(store[cnt] != 0)
                    cnt++;
                ans += cnt;
                store[cnt]++;
            }
            else
                ans += s[i];
        }
        printf("%d\n", ans - sum);
    }
    return 0;
}