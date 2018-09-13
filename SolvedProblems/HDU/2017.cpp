#include <stdio.h>

int main()
{
    int num = 0;
    while(~scanf("%d", &num))
    {
        getchar();
        for(int i = 0; i < num; i++)
        {
            char c;
            int count = 0;
            while(~scanf("%c", &c))
            {
                if(c >= '0' && c <= '9')
                    count++;
                if(c == '\n')
                    break;
            }
            printf("%d\n", count);
        }
    }
}