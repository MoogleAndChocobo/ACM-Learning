#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    int i;
    while(~scanf("%d", &n))
    {
        if(n == 0)
            break;
        int judge1 = 0, judge2 = 0;
        int k = n/1000 + n%1000/100 + n%100/10 + n%10;
        int sum = 0;
        int temp = n;
        for(i = 3; i >= 0; i--)
        {
            sum += temp % 16;
            temp /= 16;
            
        }
        if(sum == k)
            judge1 = 1;
        
        sum = 0;
        temp = n;
        for(i = 3; i >= 0; i--)
        {
            sum += temp % 12;
            temp /= 12;
        }
        if(sum == k)
            judge2 = 1;
        
        if(judge1 && judge2)
            printf("%d is a Sky Number.\n", n);
        else
            printf("%d is not a Sky Number.\n", n);
    }
}