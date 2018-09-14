#include<cstdio>

int main()
{
    int n, mycount = 0;
    scanf("%d", &n);
    while(n--)
    {
        int t, counthere = 0;
        for(int i = 0; i < 3; i++)
        {
            scanf("%d", &t);
            if(t)
                counthere++;
        }
        if(counthere >= 2)
            mycount++;
    }
    printf("%d\n", mycount);
    return 0;
}