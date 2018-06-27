#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <ctime>
#include <bitset>
#include <cmath>
#include <cctype>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define sfs(a) scanf("%s", a)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define pb(a) push_back(a)
#define all(a) a.begin(),a.end()


const int N = 1e3 + 10;
const int MAX = 1e3;
const LL INF = 0x3f3f3f3f;

//#define LOCAL

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "r", stdout);
#endif

    int n;
    while(~sfi(n) && n)
    {
        int p = (n - 1960) / 10 + 2;
        p = 1<<p;
        double sum = 0.0, fac = 1.0;
        while (sum < (double)p)
            sum += log(fac) / log(2.), fac += 1.;
        printf("%d\n", int(fac - 2.));
    }


    return 0;
}
