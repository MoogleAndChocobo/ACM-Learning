//~ #define LOCAL

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

const int MAX = 1e6 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const LL LINF = 0x3f3f3f3f3f3f3f;

#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfc(a) scanf("%c", &c)
#define sfs(a) scanf("%s", a)
#define sfd(a) scanf("%lf", &a)
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))

char a[MAX], b[MAX];

void check(char s[])
{
    int len = strlen(s);
    bool flag = false;
    rep(i, 0, len - 1)
    {
        if(s[i] == '.')
        {
            flag = true;
            break;
        }
    }
    if(flag)
    {
        dow(i, len - 1, 0)
        {
            if(s[i] == '0')
            {
                s[i] = '\0';
                len--;
            }
            else
                break;
        }
        if(s[len - 1] == '.')
            s[len - 1]  = '\0';
    }
}

int main()
{
    
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif    //LOCAL

    //ios::sync_with_stdio(false);
    //cin.tie(0);

    while(~scanf("%s%s", a, b))
    {
        check(a);
        check(b);
        if(!strcmp(a, b))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}