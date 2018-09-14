#include<cstdio>
#include<cstring>

const int MAX = 20;

int main()
{
    int n;
    char temp[MAX] = {0};
    char judge[MAX] = {0};
    while(~scanf("%d%s%s", &n, temp, judge))
    {
        if(strcmp(judge, "week") == 0)
        {
            if(n == 6 || n == 5)
                printf("53\n");
            else
                printf("52\n");
        }
        else
        {
            if(n == 31)
                printf("7\n");
            else if(n == 30)
                printf("11\n");
            else
                printf("12\n");
        }
    }
    return 0;
}