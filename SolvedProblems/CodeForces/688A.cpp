#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAX = 105;
char s[MAX] = {0};

int main()
{
    int len, n;
    scanf("%d%d", &len, &n);
    int cnt = 0;
    int mx = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%s", s);
        bool flag = false;
        for(int j = 0; j < len; j++)
        {
            if(s[j] != '1')
            {
                flag = true;
                break;
            }
        }
        if(flag)
            cnt++;
        else
            cnt = 0;
        mx = max(mx, cnt);
    }
    printf("%d\n", mx);
    return 0;
}