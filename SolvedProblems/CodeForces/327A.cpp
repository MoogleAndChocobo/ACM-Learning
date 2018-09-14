#include<cstdio>
#include<algorithm>

using namespace std;

const int MAX = 105;

int main()
{
    int n;
    scanf("%d", &n);
    int s[MAX] = {0};
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%1d", &s[i]);
        if(s[i] == 1)
            sum++;
    }
    if(sum == n)
    {
        printf("%d", n - 1);
        return 0;
    }
    int maxsum = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= n - i; j++)
        {
            int cnt1, cnt0;
            cnt1 = cnt0 = 0;
            for(int k = j; k < i + j; k++)
            {
                if(s[k])
                    cnt1++;
                else
                    cnt0++;
            }
            maxsum = max(maxsum, cnt0 - cnt1);
        }
    }
    printf("%d", maxsum + sum);
    return 0;
}