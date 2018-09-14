#include<cstdio>
#include<iostream>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstdlib>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)
#define mst(a) memset(a, 0, sizeof(a))
#define PNT putchar('\n')

typedef long long LL;

const int INF = 0xffffffff;
const int MAXN = 1e5 + 10;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a, b;
    while(cin >> a >> b)
    {
        if(a == b)
            printf("-1\n");
        else
            printf("%d\n", max(a.size(), b.size()));
    }
    return 0;
}