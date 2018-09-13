#include <stdio.h>
int main()
{
    int num;
    while(~scanf("%d", &num))
    {
        int sum = 1;
        for(int i = 0; i < num - 1; i++)
        {
            sum = 2 * sum + 2;
        }
        printf("%d\n", sum);
    }
}