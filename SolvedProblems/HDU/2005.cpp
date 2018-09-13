#include <stdio.h>
int main()
{
    
    const int COMMONYEAR[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const int LEAPYEAR[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year, month, day;
    while(scanf("%d/%d/%d", &year, &month, &day) != EOF)
    {
        int judge = 0, count = 0;
        int i;
        if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            judge = 1;
        if(judge == 0)
        {
            for(i = 0; i < month - 1; i++)
            {
                count += COMMONYEAR[i];
            }
            count += day;
            printf("%d\n", count);
        }
        if(judge == 1)
        {
            for(i = 0; i < month - 1; i++)
            {
                count += LEAPYEAR[i];
            }
            count += day;
            printf("%d\n", count);
        }
    }
}