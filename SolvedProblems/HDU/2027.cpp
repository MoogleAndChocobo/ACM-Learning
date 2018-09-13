#include <stdio.h>
#include <string.h>

int main()
{
    int num;
    scanf("%d", &num);
    getchar();
    for(int i = 0; i < num; i++)
    {
        int a_count = 0;
        int e_count = 0;
        int i_count = 0;
        int o_count = 0;
        int u_count = 0;
        char c;
        for(int j = 0; j < 100; j++)
        {
            scanf("%c", &c);
            if(c == '\n')
                break;
            if(c == 'a')
                a_count++;
            else if(c == 'e')
                e_count++;
            else if(c == 'i')
                i_count++;
            else if(c == 'o')
                o_count++;
            else if(c == 'u')
                u_count++;
        }
        printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n", a_count, e_count, i_count, o_count, u_count);;
        if(i != num - 1)
            printf("\n");
    }
}