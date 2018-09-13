#include <stdio.h>

int main()
{
    int num;
    int judge = 0;
    while(~scanf("%d", &num))
    {
        if(num == 0)
            break;
        if(judge == 1)
            printf("\n");
        int s[50] = {0};
        int sum = 0;
        for(int i = 0; i < num; i++)
        {
            scanf("%d", &s[i]);
            sum += s[i];
        }
        int ave = sum / num;
        int count = 0;
        for(int i = 0; i < num; i++)
        {
            if(s[i] > ave)
                count += s[i] - ave;
        }
        printf("%d\n", count);
        judge = 1;
    }
}