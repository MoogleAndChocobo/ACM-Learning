#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int s[110] = {0};
    for(int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    int cnt = 0;
    int mn = s[0];
    for(int i = 0; i < n; i++)
        mn = min(mn, s[i]);
    if(s[n - 1] != mn)
    {
        for(int i = n - 2; i >= 0; i--)
        {
            if(s[i] == mn)
            {
                for(int j = i; j < n - 1; j++)
                {
                    swap(s[j], s[j + 1]);
                    cnt++;
                }
                break;
            }
        }
    }
    int mx = s[0];
    for(int i = 1; i < n; i++)
        mx = max(mx, s[i]);
    if(s[0] != mx)
    {
        for(int i = 1; i < n; i++)
        {
            if(s[i] == mx)
            {
                for(int j = i; j > 0 ; j--)
                {
                    swap(s[j], s[j - 1]);
                    cnt++;
                }
                break;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}