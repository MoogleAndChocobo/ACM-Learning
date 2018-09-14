#include<cstdio>
#include<algorithm>

using namespace std;

const int MAX = 100010;
int ans[MAX] = {0};

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int t1, t2;
        scanf("%d%d", &t1, &t2);
        ans[t1] = t2;
    }
    for(int i = 1; i < n; i++)
    {
        if(ans[i] > ans[i + 1])
        {
            printf("Happy Alex\n");
            return 0;
        }
    }
    printf("Poor Alex\n");
    return 0;
}