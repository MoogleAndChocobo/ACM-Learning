#include <stdio.h>
#include <math.h>

int main()
{
    int min, max;
    while(~scanf("%d%d", &min, &max))
    {
        int count = 0;
        int s[100] = {0};
        for(int num = min; num <= max; num++)
        {
            if(num / 100 < 10 && num / 100 >= 1)
            {
                if(pow(num / 100, 3) + pow(num % 100 / 10, 3) + pow(num % 10, 3) == num)
                {
                    s[count] = num;
                    count++;
                }
            }
        }
        if(count == 0)
            printf("no\n");
        else{
            for(int i = 0; i < count; i++)
            {
                for(int j = 1; j < count - i; j++)
                {
                    if(s[j] < s[j - 1])
                    {
                        int temp = s[j];
                        s[j] = s[j - 1];
                        s[j - 1] = temp;
                    }
                }
            }
            for(int i = 0; i < count; i++)
            {
                printf("%d", s[i]);
                if(i != count - 1)
                    printf(" ");
                else
                    printf("\n");
            }
        }
    }
    return 0;
}