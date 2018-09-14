#include<cstdio>

const int MAX = 100010;

int main()
{
    int n;
    scanf("%d", &n);
    int s[MAX] = {0};
    for(int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    int count25, count50;
    count25 = count50 = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 25)
            count25++;
        else if(s[i] == 50)
        {
            if(count25 == 0)
            {
                printf("NO");
                return 0;
            }
            count50++;
            count25--;
        }
        else if(s[i] == 100)
        {
            if(count50 != 0 && count25 != 0)
            {
                count50--;
                count25--;
            }
            else if(count25 >= 3)
                count25 -= 3;
            else
            {
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES");
    return 0;
}