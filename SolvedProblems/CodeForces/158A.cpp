#include<cstdio>

int main()
{
    int n, num;
    scanf("%d%d", &n, &num);
    int s[110] = {0};
    for(int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    int mycount = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 0 && i <= num - 1)
        {
            printf("%d\n", i);
            return 0;
        }
        else if(s[i] >= s[num - 1])
            mycount++;
    }
    printf("%d\n", mycount);
    return 0;
}