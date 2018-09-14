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

using namespace std;

typedef long long LL;

int main()
{
    char s[15][15] = {0};
    int m, n;
    scanf("%d%d", &m, &n);
    for(int i = 0; i < m; i++)
        scanf("%s", s[i]);
    int sum, cnt1, cnt2;
    sum = cnt1 = cnt2 = 0;
    for(int i = 0; i < m; i++)
    {
        string ss = s[i];
        if(ss.find("S") == -1)
        {
            sum += n;
            cnt1++;
        }
    }
    for(int i = 0; i < n; i++)
    {
        bool flag = true;
        for(int j = 0; j < m; j++)
        {
            if(s[j][i] == 'S')
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            sum += m;
            cnt2++;
        }
    }
    printf("%d\n", sum - cnt1 * cnt2);
    return 0;
}