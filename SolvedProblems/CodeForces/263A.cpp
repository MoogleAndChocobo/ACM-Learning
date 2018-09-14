#include<cstdio>

int main()
{
    int s[5][5] = {0};
    int x, y;
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
        {
            scanf("%d", &s[i][j]);
            if(s[i][j])
            {
                x = i;
                y = j;
            }
        }
    int sum = (x - 2 > 0) ? (x - 2) : (2 - x);
    sum += (y - 2 > 0) ? (y - 2) : (2 - y);
    printf("%d\n", sum);
    return 0;
}