#include <stdio.h>
#include <string.h>

int main()
{
    int stu, les;
    double s[100][100], judge[100];
    double ave, sum;
    while(~scanf("%d%d", &stu, &les))
    {
        memset(s, 0, sizeof(s));
        for(int i = 0; i < stu; i++)
            for(int j = 0; j < les; j++)
                scanf("%lf", &s[i][j]);
        for(int i = 0; i < stu; i++)
        {
            ave = 0, sum = 0;
            for(int j = 0; j < les; j++)
                sum += s[i][j];
            printf("%.2f", sum / les);
            if(i == stu - 1)
                printf("\n");
            else
                printf(" ");
        }
        
        memset(judge, 0, sizeof(judge));
        for(int i = 0; i < les; i++)
        {
            ave = 0, sum = 0;
            for(int j = 0; j < stu; j++)
                sum += s[j][i];
            judge[i] = sum / stu;
            printf("%.2f", judge[i]);
            if(i == les - 1)
                printf("\n");
            else
                printf(" ");
        }
        
        
        int count = 0;
        for(int i = 0; i < stu; i++)
        {
            int x = 1;
            for(int j = 0; j < les; j++)
            {
                if(s[i][j] < judge[j])
                {
                    x = 0;
                    break;
                }
            }
            if(x == 1)
                count++;
        }
        printf("%d\n\n", count);
    }
    return 0;
}