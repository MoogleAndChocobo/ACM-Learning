#include <stdio.h>

int main()
{
    int num1, num2;
    int i, j;
    while(~scanf("%d%d", &num1, &num2))
    {
        if(num1 == 0 && num2 == 0)
            break;
        int s1[100] = {0};
        int s2[100] = {0};
        int s[100] = {0};
        for(i = 0; i < num1; i++)
            scanf("%d", &s1[i]);
        for(i = 0; i < num2; i++)
            scanf("%d", &s2[i]);
            
        if(num2 == 0)
        {
            for(i = 0; i < num1; i++)
            {
                for(j = 1; j < num1 - i; j++)
                {
                    if(s1[j] < s1[j - 1])
                    {
                        int temp = s1[j];
                        s1[j] = s1[j - 1];
                        s1[j - 1] = temp; 
                    }
                }
            }
            for(i = 0; i < num1; i++)
                printf("%d ", s1[i]);
            printf("\n");
            continue;
        }
                
        int count = 0;
        for(i = 0; i < num1; i++)
        {
            for(j = 0; j < num2; j++)
            {
                if(s1[i] == s2[j])
                    break;
                if(j == num2 - 1)
                {
                    s[count] = s1[i];
                    count++;
                }
            }
        }
        
        if(count == 0)
            printf("NULL\n");
        else{
            for(i = 0; i < count; i++)
            {
                for(j = 1; j < count - i; j++)
                {
                    if(s[j] < s[j - 1])
                    {
                        int temp = s[j];
                        s[j] = s[j - 1];
                        s[j - 1] = temp; 
                    }
                }
            }
            for(i = 0; i < count; i++)
                printf("%d ", s[i]);
            printf("\n");
        }
    }
}