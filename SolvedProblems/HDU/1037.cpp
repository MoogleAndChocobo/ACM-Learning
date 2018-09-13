#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<map>
#include<set>
#include<cctype>
#include<cmath>

using namespace std;

typedef long long LL;
typedef unsigned U;

const int MAX = 1e3 + 10;
const int INF = 0x3f3f3f3f;
const int N = 168;
const int MOD = 1e9 + 7;
const LL LINF = 0x3f3f3f3f3f3f3f;
const LL LMT = 3 * N + 10;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define sfd(a) scanf("%lf", &a)

int main()
{
#ifdef LOCAL
    //~ freopen("in.txt", "r", stdin);
#endif    //LOCAL

    int s[MAX];
    bool flag = true;
    rep(i, 1, 3)
    {
        sfi(s[i]);
        if(s[i] < N)
            flag = false;
    }
    if(flag)
        puts("NO CRASH");
    else
    {
        printf("CRASH");
        rep(i, 1, 3)
            if(s[i] < N)
                printf(" %d", s[i]);
        putchar('\n');
    }
    return 0;
}