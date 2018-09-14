#include<cstdio>

const int MAX = 100010;

int s0[MAX] = {0};

int main()
{
    int s[4] = {0};
    int n;
    for(int i = 0; i < 4; i++)
        scanf("%d", &s[i]);
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        s0[i] = i + 1;
    int cnt = 0;
    for(int j = 0; j < 4; j++)
    {
        for(int i = 0; i < n; i++)
            if(s0[i] % s[j] == 0)
            s0[i] = 0;
    }
    for(int i = 0; i < n; i++)
        if(s0[i] == 0)
            cnt++;
    printf("%d\n", cnt);
    return 0;
}