#include<stdio.h>
int main()
{
    int n;
    int i;
    char m[12];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",m);
        printf("6%s\n",m+6);

    }
    return 0;
}