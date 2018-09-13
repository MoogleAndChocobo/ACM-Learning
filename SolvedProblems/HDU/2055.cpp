#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);
    getchar();
    for(int j = 0; j < num; j++)
    {
        char c;
        int i;
        scanf("%c", &c);
        scanf("%d", &i);
        getchar();
        if(c >= 'A' && c <= 'Z')
            i += c - 64;
        if(c >= 'a' && c <= 'z')
            i += -(c - 96);
        printf("%d\n", i);
    }
}