#include<cstdio>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int cnt = 0;
    while(n)
    {
        cnt++;
        if(cnt % m == 0)
            n++;
        n--;
    }
    printf("%d\n", cnt);
    return 0;
}