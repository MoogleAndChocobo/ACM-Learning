#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<time.h>
#include<set>
#include<algorithm>
#include<sstream>
#include<cctype>

using namespace std;

typedef long long LL;

int main()
{
    LL n, st;
    scanf("%lld%lld", &n, &st);
    getchar();
    LL cnt = 0;
    for(LL i = 0; i < n; i++)
    {
        char c;
        LL temp;
        scanf("%c%lld", &c, &temp);
        getchar();
        if(c == '+')
            st += temp;
        else
        {
            if(temp <= st)
                st -= temp;
            else
                cnt++;
        }
    }
    printf("%lld %lld\n", st, cnt);
    return 0;
}