#include<cstdio>

#define FOR(i, a, b) for(int i = a; i <= b; i++)

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        int chest, biceps, back;
        chest  = biceps = back = 0;
        FOR(i, 1, n)
        {
            int temp;
            scanf("%d", &temp);
            if(i % 3 == 1)
                chest += temp;
            else if(i % 3 == 2)
                biceps += temp;
            else
                back += temp;
        }
        if(back > chest && back > biceps)
            printf("back\n");
        else if(chest > back && chest > biceps)
            printf("chest\n");
        else
            printf("biceps\n");
    }
    return 0;
}