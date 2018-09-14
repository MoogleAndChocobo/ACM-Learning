#include<cstdio>
#include<algorithm>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)
#define PNT putchar('\n')

const int MAX = 1e5 + 10;

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        int s[MAX] = {0};
        FOR(i, 0, n - 1)
            scanf("%1d", &s[i]);
        int cnt = n;
        FOR(i, 0, n - 1)
        {
            if(s[i] == 4)
            {
                s[i] = 3;
                s[cnt++] = 2;
                s[cnt++] = 2;
            }
            else if(s[i] == 6)
            {
                s[i] = 5;
                s[cnt++] = 3;
            }
            else if(s[i] == 8)
            {
                s[i] = 7;
                s[cnt++] = 2;
                s[cnt++] = 2;
                s[cnt++] = 2;
            }
            else if(s[i] == 9)
            {
                s[i] = 7;
                s[cnt++] = 3;
                s[cnt++] = 3;
                s[cnt++] = 2;
            }
        }
        sort(s, s + cnt);
        ROF(i, cnt - 1, 0)
            if(s[i] != 0 && s[i] != 1)
                printf("%d", s[i]);
            else
                break;
        PNT;
    }
    return 0;
}