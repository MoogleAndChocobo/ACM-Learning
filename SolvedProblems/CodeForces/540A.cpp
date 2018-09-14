#include<cstdio>
#include<algorithm>

using namespace std;

const int MAX = 1005;

int main()
{
    int n;
    scanf("%d", &n);
    int st[MAX] = {0}, en[MAX] = {0};
    for(int i = 0; i < n; i++)
        scanf("%1d", &st[i]);
    for(int i = 0; i < n; i++)
        scanf("%1d", &en[i]);
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        int temp = (st[i] - en[i] > 0) ? st[i] - en[i] : en[i] - st[i];
        cnt += min(temp, 10 - temp);
    }
    printf("%d", cnt);
    return 0;
}