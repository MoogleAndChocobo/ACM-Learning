#include<cstdio>

int main()
{
    int num;
    scanf("%d", &num);
    int cntm, cntc;
    cntm = cntc = 0;
    for(int i = 0; i < num; i++)
    {
        int m, c;
        scanf("%d%d", &m, &c);
        if(m > c)
            cntm++;
        else if(m < c)
            cntc++;
    }
    if(cntm > cntc)
        printf("Mishka");
    else if(cntm < cntc)
        printf("Chris");
    else
        printf("Friendship is magic!^^");
    return 0;
}