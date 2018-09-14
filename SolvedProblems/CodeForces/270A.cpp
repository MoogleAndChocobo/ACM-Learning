#include<cstdio>

bool judge(int t)
{
    if(360 % (180 - t) == 0)
        return true;
    return false;
}

int main()
{
    int num;
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    {
        int t;
        scanf("%d", &t);
        if(judge(t))
            printf("YES");
        else
            printf("NO");
        if(i != num - 1)
            printf("\n");
    }
    return 0;
}