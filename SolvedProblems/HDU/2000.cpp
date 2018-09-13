#include <stdio.h>
int main()
{
    char a[10];
    char temp;
    int i, j;
    while(gets(a))
    {
        for(i = 0; i < 3; i++)
        {
            for(j = i; j < 3; j++)
            {
                if(a[i] >= a[j])
                {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
        for(i = 0; i < 3; i++)
        {
            printf("%c", a[i]);
            if(i == 1 || i == 0)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}