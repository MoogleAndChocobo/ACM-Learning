#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>

using namespace std;

typedef long long LL;

const int MAX = 1e2 + 10;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define pb(a) push_back(a)
#define mst(a, b) memset(a, b, sizeof(a))
#define sfl(a) scanf("%lld", &a)

int main()
{
#ifdef LOCAL
    //~ freopen("in.txt", "r", stdin);
#endif    //LOCAL

    int T;
    sfi(T);
    rep(i, 1, T)
    {
        LL m;
        sfl(m);
        LL n = m % 10;
        if(n == 0)
            puts("0");
        else if(n == 1)
            puts("1");
        else if(n == 2)
        {
            int s[MAX] = {6, 2, 4, 8};
            printf("%d\n", s[m % 4]);
        }
        else if(n == 3)
        {
            int s[MAX] = {1, 3, 9, 7};
            printf("%d\n", s[m % 4]);
        }
        else if(n == 4)
        {
            int s[MAX] = {6, 4};
            printf("%d\n", s[m % 2]);
        }
        else if(n == 5)
            puts("5");
        else if(n == 6)
            puts("6");
        else if(n == 7)
        {
            int s[MAX] = {1, 7, 9, 3};
            printf("%d\n", s[m % 4]);
        }
        else if(n == 8)
        {
            int s[MAX] = {6, 8, 4, 2};
            printf("%d\n", s[m % 4]);
        }
        else if(n == 9)
        {
            int s[MAX] = {1, 9};
            printf("%d\n", s[m % 2]);
        }
    }
    return 0;
}