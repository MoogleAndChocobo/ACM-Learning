#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);
    getchar();
    for(int i = 0; i < num; i++)
    {
        int count = 0;
        char c;
        while(~scanf("%c", &c))
        {
            if(c == '\n')
                break;
            if(c < 0)
                count++;
        }
        printf("%d\n", count / 2);
    }
}