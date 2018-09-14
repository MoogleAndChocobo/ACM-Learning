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

set<int> ans;

int main()
{
    int n, sum;
    scanf("%d%d", &n, &sum);
    for(int i = 0; i < n; i++)
    {
        int times;
        scanf("%d", &times);
        for(int j = 0; j < times; j++)
        {
            int temp;
            scanf("%d", &temp);
            ans.insert(temp);
        }
    }
    if(ans.size() == sum)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}