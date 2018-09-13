#include <stdio.h>
int main()
{
    int num, step;
    while(~scanf("%d%d", &num, &step))
    {
        int count = num / step;
        int temp = 2;
        for(int i = 0; i < count; i++)
        {
            int sum = 0;
            for(int j = 0; j < step; j++)
            {
                sum += temp;
                temp += 2;
            }
            printf("%d", sum / step);
            if(i != count - 1)
                printf(" ");
            else{
                if(num % step)
                    printf(" ");
                else
                    printf("\n");
            }
        }
        if(num % step)
        {
            int sum = 0;
            for(int j = 0; j < num % step; j++)
            {
                sum += temp;
            }
            printf("%d\n", sum / (num % step));
        }
    }
}