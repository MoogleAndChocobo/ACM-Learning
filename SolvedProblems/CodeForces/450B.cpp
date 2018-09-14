#include<bits/stdc++.h>
 
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
 
const int MAX = 1e2 + 10;
const int INF = 0x3f3f3f3f;
const int INIT = INF;
const LL MOD = 1e9 + 7;
 
#define sfi(a) scanf("%d", &a)
#define sfd(a) scanf("%lf", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
 
#define rep(i, a, b) for(LL i = (LL)a; i <= (LL)b; ++i)
#define dow(i, a, b) for(LL i = (LL)a; i >= (LL)b; --i)
 
#define mem(a) memset(a, 0, sizeof(a))
#define msf(a) memset(a, INF, sizeof(a))
 
struct Matrix
{
    LL p[MAX][MAX];
    Matrix operator *(const Matrix &a)const
    {
        Matrix ret;
        mem(ret.p);
        rep(i, 0, 1)
            rep(j, 0, 1)
                rep(k, 0, 1)
                    ret.p[i][j] = (ret.p[i][j] + p[i][k] * a.p[k][j]) % MOD;
        return ret;
    }
    Matrix operator ^(const LL &a)const
    {
        Matrix ret;
        mem(ret.p);
        rep(i, 0, 1)
            ret.p[i][i] = 1;
        LL m = a;
        Matrix tmp;
        rep(i, 0, 1)
            rep(j, 0, 1)
                tmp.p[i][j] = p[i][j];
        while(m)
        {
            if(m & 1)
                ret = ret * tmp;
            tmp = tmp * tmp;
            m >>= 1;
        }
        return ret;
    }
 
    void init(void)
    {
        mem(p);
        return;
    }
} ma;
 
LL f(LL b)
{
    LL a = 2;
    LL ans = 1;
    a %= MOD;
    while(b)
    {
        if(b % 2)
        {
            ans *= a;
            ans %= MOD;
        }
        a *= a;
        a %= MOD;
        b >>= 1;
    }
    return ans;
}
 
int main()
{
     
#ifdef LOCAL
    //~ freopen("in.txt", "r", stdin);
#endif
 
    LL x, y, n;
    while(~scanf("%lld%lld%lld", &x, &y, &n))
    {
        ma.init();
        LL ans = 0;
        if(n == 1)
            ans = x;
        else if(n == 2)
            ans = y;
        else
        {
            LL k = n - 2;
            ma.p[0][0] = ma.p[1][0] = 1;
            ma.p[1][1] = 0;
            ma.p[0][1] = -1;
            ma = ma ^ k;
            ans = (ma.p[0][0] * y + ma.p[0][1] * x) % MOD;
        }
        if(ans < 0)
            ans += MOD;
        printf("%lld\n", ans);
    }
    return 0;
}