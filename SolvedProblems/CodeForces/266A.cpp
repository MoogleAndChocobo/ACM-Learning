#include<cstdio>

int main()
{
    int n, cnt = 0;
    scanf("%d", &n);
    getchar();
    char flag1, flag2;
    scanf("%c", &flag1);
    for(int i = 0; i < n; i++)
    {
        scanf("%c", &flag2);
        if(flag1 == flag2)
            cnt++;
        flag1 = flag2;
    }
    printf("%d\n", cnt);
    return 0;
}