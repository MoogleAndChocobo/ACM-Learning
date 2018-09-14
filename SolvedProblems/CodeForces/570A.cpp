#include<cstdio>
#include<algorithm>

using namespace std;

int s[105][105] = {0};

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int index = 0, mx = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            scanf("%d", &s[i][j]);
    }
    int ans[105] = {0};
    for(int i = 0; i < m; i++)
    {
        int mx = s[i][0];
        for(int j = 0; j < n; j++)
        {
            if(s[i][j] > mx)
            {
                mx = s[i][j];
                ans[i] = j;
            }
        }
    }
    sort(ans, ans + m);
    mx = 1;
    int mxhere = 1, get = ans[0];
    for(int i = 1; i < m; i++)
    {
        if(ans[i] == ans[i - 1])
            mxhere++;
        else
            mxhere = 1;
        if(mxhere > mx)
        {
            mx = mxhere;
            get = ans[i];
        }
    }
    printf("%d", get + 1);
    return 0;
}