#include <stdio.h>

int main()
{
    const int s[6] = {100, 50, 10, 5, 2, 1};
    int num;
    while(~scanf("%d", &num))
    {
        if(num == 0)
            break;
            
        int count = 0;
        for(int i = 0; i < num; i++)
        {
            int n;
            scanf("%d", &n);
            for(int j = 0; j < 6; j++)
            {
                count += n / s[j];
                n -= n / s[j] * s[j];
            }
        }
        printf("%d\n", count);
    }
}