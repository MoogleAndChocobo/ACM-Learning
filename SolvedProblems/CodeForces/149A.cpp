#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int mymin;
    scanf("%d", &mymin);
    int s[12] = {0};
    for(int i = 0; i < 12; i++)
        scanf("%d", &s[i]);
    sort(s, s + 12);
    int sum, judge;
    sum = judge = 0;
    bool flag = false;
    if(mymin == 0)
    {
        printf("0");
        return 0;
    }
    for(int i = 11, j = 1; i >= 0; i--, j++)
    {
        sum += s[i];
        if(sum >= mymin)
        {
            flag = true;
            judge = j;
            break;
        }
    }
    if(flag)
        printf("%d", judge);
    else
        printf("-1");
    return 0;
}