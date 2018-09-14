#include<cstdio>

int main()
{
    int num;
    scanf("%d", &num);
    double x;
    for(int i = 0; i < num; i++)
    {
        int temp;
        scanf("%d", &temp);
        x += (double)temp;
    }
    printf("%.12lf", x / num);
    return 0;
}