#include<cstdio>

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define PNT putchar('\n')

const int MAXN = 5 * 1e5 + 10;

int main()
{
    int n, judge;
    while(~scanf("%d%d", &n, &judge))
    {
        int cnt = 0;
        int ans[MAXN] = {0};
        FOR(i, 1, n)
        {
            int num;
            scanf("%d", &num);
            bool flag = false;
            while(num--)
            {
                int temp;
                scanf("%d", &temp);
                if(judge > temp)
                    flag = true;
            }
            if(flag)
                ans[cnt++] = i;
        }
        printf("%d\n", cnt);
        FOR(i, 0, cnt - 1)
        {
            printf("%d", ans[i]);
            if(i != cnt - 1)
                printf(" ");
            else
                PNT;
        }
    }
    return 0;
}