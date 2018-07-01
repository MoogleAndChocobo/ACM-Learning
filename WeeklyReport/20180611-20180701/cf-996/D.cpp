#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <cmath>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef unsigned U;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a) memset(a, b, sizeof(a))
#define pb(a) push_back(a)
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define sfu(a) scanf("%llu", &a)
#define sfs(a) scanf("%s", a)

const int INF = 0x3f3f3f3f;
const int MAX = 1e3 + 10;
const int N = 1e3;

int main()
{
    int n;
    while(~sfi(n))
    {
        n *= 2;
        int s[MAX] = {0};

        rep(i, 1, n)
        {
            sfi(s[i]);
        }


        int ans = 0;
        for(int i = 1; i <= n; i += 2)
        {
            rep(j, i + 1, n)
            {
                if(s[j] == s[i])
                {
                    dow(k, j, i + 2)
                        s[k] = s[k - 1];
                    ans += j - i - 1;
                    break;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
