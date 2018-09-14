#include<cstdio>

const int MAXN = 105;

int main()
{
    int num, m;
    scanf("%d%d", &num, &m);
    getchar();
    char s[MAXN][MAXN] = {0};
    bool flag = true;
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%c", &s[i][j]);
            if(s[i][j] == 'C' || s[i][j] == 'M' || s[i][j] == 'Y')
            {
                flag = false;
            }
            getchar();
        }
    }
    if(flag)
        printf("#Black&White");
    else
        printf("#Color");
    return 0;
}