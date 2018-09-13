#include <stdio.h>
#include <string.h>

int main()
{
    int num;
    scanf("%d", &num);
    getchar();
    for(int i = 0; i < num; i++)
    {
        char s[51] = {0};
        gets(s);
        
        int judge = 0;
        if(strlen(s) >= 8 && strlen(s) <= 16)
            judge = 1;
        
        int count0 = 0, count1 = 0, count2 = 0, count3 = 0;
        for(int j = 0; j < strlen(s); j++)
        {
            if(s[j] >= 'A' && s[j] <= 'Z')
                count0++;
            if(s[j] >= 'a' && s[j] <= 'z')
                count1++;
            if(s[j] >= '0' && s[j] <= '9')
                count2++;
            if(s[j] == '~' || s[j] == '!' || s[j] == '@' || s[j] == '#' || s[j] == '$' || s[j] == '%' || s[j] == '^')
                count3++;
        }
        int count = 0;
        if(count0 != 0)
            count++;
        if(count1 != 0)
            count++;
        if(count2 != 0)
            count++;
        if(count3 != 0)
            count++;
            
        if(count >= 3 && judge == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
}