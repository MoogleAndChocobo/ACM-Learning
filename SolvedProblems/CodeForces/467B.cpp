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

int s[1010][25] = {0};

int main()
{
    int type, num, dif;
    scanf("%d%d%d", &type, &num, &dif);
    for(int i = 0; i < num; i++)
    {
        int temp;
        scanf("%d", &temp);
        for(int j = 0; j < type; j++)
        {
            s[i][j] = temp % 2;
            temp /= 2;
        }
    }
    int judge;
    scanf("%d", &judge);
    int get[25] = {0};
    for(int i = 0; i < type; i++)
    {
        get[i] = judge % 2;
        judge /= 2;
    }
    int cnt = 0;
    for(int i = 0; i < num; i++)
    {
        int cnt_here = 0;
        for(int j = 0; j < type; j++)
        {
            if(s[i][j] != get[j])
                cnt_here++;
        }
        if(cnt_here <= dif)
            cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}