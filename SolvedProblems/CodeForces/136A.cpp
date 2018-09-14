#include<cstdio>

int main()
{
    int num, t, s[105];
    scanf("%d", &num);
    for(int i = 1; i <= num; )
    {
        scanf("%d", &t);
        s[t] = i++;
    }
    for(int i = 1; i <= num; i++)
    {
        printf("%d", s[i]);
        if(i != num)
            printf(" ");
    }
    return 0;
}