#include<cstdio>

#define FOR(i, a, b) for(int i = a; i <= b; i++)

const int MAX = 1e5 + 10;
char s[MAX] = {0};
int ans[MAX] = {0};

int main()
{
    char c;
    int cnt = 1;
    scanf("%c", &s[0]);
    while(scanf("%c", &c) && c != '\n')
    {
        s[cnt] = c;
        ans[cnt] = ans[cnt - 1];
        if(s[cnt] == s[cnt - 1])
            ans[cnt]++;
        cnt++;
    }
    int n;
    scanf("%d", &n);
    FOR(i, 0, n - 1)
    {
        int mx, mn;
        scanf("%d%d", &mn, &mx);
        printf("%d\n", ans[mx - 1] - ans[mn - 1]);
    }
    return 0;
}