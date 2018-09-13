
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<iostream>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<list>
#include<cctype>
#include<ctime>
#include<functional>
#include<cmath>

using namespace std;

typedef unsigned U;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> pii;

const int MAX = 1e3 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const LL LINF = 0x3f3f3f3f3f3f3f;

#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfc(a) scanf("%c", &c)
#define sfs(s) scanf("%s", s);
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))

LL gt(char c)
{
    if(isdigit(c))
        return c - '0';
    if(isupper(c))
        return c - ('A' - 10);
    return c - ('a' - 10);
}

int main()
{
    
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif    //LOCAL

    //ios::sync_with_stdio(false);
    //cin.tie(0);

    char a[MAX] = {0}, b[MAX] = {0};
    while(scanf("%s %s", a, b) == 2)
    {
        LL m = 0, n = 0;
        LL lena = strlen(a), lenb = strlen(b);
        LL mypow = 1;
        dow(i, lena - 1, 0)
        {
            m += mypow * gt(a[i]);
            mypow *= 16;
        }
        mypow = 1;
        dow(i, lenb - 1, 0)
        {
            n += mypow * gt(b[i]);
            mypow *= 16;
        }
        printf("%lld\n", m + n);
    }
    return 0;
}