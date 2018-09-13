#include <stdio.h>

int main()
{
    int plus, product;
    int i;
    while(~scanf("%d%d", &plus, &product))
    {
        int judge = 0;
        if(plus == 0 && product == 0)
            break;
        for(i = -10000; i <= 10000; i++)
        {
            if(i * (plus - i) == product)
            {
                judge = 1;
                break;
            }
        }
        if(judge == 1)
            printf("Yes\n");
        else
            printf("No\n");
    }
}