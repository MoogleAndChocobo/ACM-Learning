#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    {
        int count;
        scanf("%d", &count);
        int sum = 3;
        for(int k = 0; k < count; k++)
        {
            sum = (sum - 1) * 2;
        }
        printf("%d\n", sum);
    }
}