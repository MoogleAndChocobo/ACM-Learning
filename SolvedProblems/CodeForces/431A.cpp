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

char s[MAX] = {0};

int main()
{
    int judge[10] = {0};
    for(int i = 1; i <= 4; i++)
        scanf("%d", &judge[i]);
    scanf("%s", s);
    int sum = 0;
    for(int i = 0; i < strlen(s); i++)
    {
        if(s[i] == '1')
            sum += judge[1];
        else if(s[i] == '2')
            sum += judge[2];
        else if(s[i] == '3')
            sum += judge[3];
        else
            sum += judge[4];
    }
    printf("%d\n", sum);
    return 0;
}