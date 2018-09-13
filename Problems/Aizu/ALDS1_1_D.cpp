#include<cstdio>
#include<algorithm>
 
using namespace std;
 
#define FOR(i, a, b) for(int i = a; i <= b; i++)
 
const int MAX = 2 * 1e5 + 10;
int s[MAX];
 
int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        FOR(i, 0, n - 1)
            scanf("%d", &s[i]);
        int mx = s[1] - s[0], nowmn = min(s[1], s[0]);
        FOR(i, 2, n - 1)
        {
            mx = max(mx, s[i] - nowmn);
            nowmn = min(s[i], nowmn);
        }
        printf("%d\n", mx);
    }
    return 0;
}