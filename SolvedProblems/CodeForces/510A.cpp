#include<cstdio>

int main()
{
    int wid, len;
    scanf("%d%d", &wid, &len);
    for(int i = 0; i < wid; i++)
    {
        if(i % 2 == 0)
            for(int i = 0; i < len; i++)
                printf("#");
        else if((i + 1) % 4)
            for(int i = 0; i < len; i++)
            {
                if(i != len - 1)
                    printf(".");
                else
                    printf("#");
            }
        else
            for(int i = 0; i < len; i++)
            {
                if(i != 0)
                    printf(".");
                else
                    printf("#");
            }
        if(i != wid - 1)
            printf("\n");
    }
    return 0;
}