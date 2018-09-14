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

const int MAX = 100000 + 10;

int s[MAX] = {0};

int main()
{
    int n, c;
    scanf("%d%d", &n, &c);
    for(int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    int cnt = 1;
    for(int i = n - 1; i >= 1; i--)
    {
        if(s[i] - s[i - 1] <= c)
            cnt++;
        else
            break;
    }
    printf("%d\n", cnt);
    return 0;
}