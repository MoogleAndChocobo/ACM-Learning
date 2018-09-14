#include<bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)

const int MAX = 1e5 + 10;

int main()
{
    char s[MAX] = {0};
    while(~scanf("%s", s))
    {
        int len = strlen(s);
        int store[MAX] = {0};
        FOR(i, 0, len - 1)
        {
            if(s[i] == 'B')
                store[0]++;
            else if(s[i] == 'u')
                store[1]++;
            else if(s[i] == 'l')
                store[2]++;
            else if(s[i] == 'b')
                store[3]++;
            else if(s[i] == 'a')
                store[4]++;
            else if(s[i] == 's')
                store[5]++;
            else if(s[i] == 'r')
                store[6]++;
        }
        store[1] /= 2;
        store[4] /= 2;
        int ans = MAX;
        FOR(i, 0, 6)
            ans = min(ans, store[i]);
        printf("%d\n", ans);
    }
    return 0;
}