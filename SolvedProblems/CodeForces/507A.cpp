#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<queue>
#include<map>
#include<time.h>
#include<vector>
#include<sstream>
#include<set>
#include<algorithm>

using namespace std;

typedef long long LL;

const int MAX = 100 + 10;

int s[MAX] = {0};
int store[MAX] = {0};

int main()
{
    int n, sum;
    scanf("%d%d", &n, &sum);
    for(int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        int index = 0;
        for(int j = 1; j < n; j++)
        {
            if(s[j] < s[index])
                index = j;
        }
        if(sum >= s[index])
        {
            sum -= s[index];
            store[cnt++] = index + 1;
            s[index] = MAX;
        }
        else
            break;
    }
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++)
    {
        printf("%d", store[i]);
        if(i != cnt - 1)
            printf(" ");
        else
            printf("\n");
    }
    return 0;
}