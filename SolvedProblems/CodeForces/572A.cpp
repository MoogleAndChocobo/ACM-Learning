#include<cstdio>

const int MAX = 100010;
int a[MAX] = {0};
int b[MAX] = {0};

int main()
{
    int na, nb, geta, getb;
    scanf("%d%d%d%d", &na, &nb, &geta, &getb);
    for(int i = 0; i < na; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < nb; i++)
        scanf("%d", &b[i]);
    if(a[geta - 1] < b[nb - getb])
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}