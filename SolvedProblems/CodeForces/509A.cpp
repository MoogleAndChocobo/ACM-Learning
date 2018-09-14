#include<cstdio>

const int MAX = 15;

int s[MAX][MAX] = {0};

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        s[0][i] = 1;
        s[i][0] = 1;
    }
    for(int  i = 1; i < n; i++)
    {
        for(int j = 1; j < n; j++)
            s[i][j] = s[i][j - 1] + s[i - 1][j];
    }
    printf("%d", s[n - 1][n - 1]);
    return 0;
}