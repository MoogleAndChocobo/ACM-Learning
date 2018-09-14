#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int s[105] = {0};
    for(int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    sort(s, s + n);
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += s[i];
    int judge = sum / 2 + 1;
    for(int i = n - 1, t = 0; i >= 0; i--)
    {
        t += s[i];
        if(t >= judge)
        {
            printf("%d", n - i);
            break;
        }
    }
    return 0;
}