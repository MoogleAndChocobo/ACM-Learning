#include<cstdio>
#include<cmath>

int main()
{
    int n;
    scanf("%d", &n);
    int a = 0, b = 0;
    for(int i = 0; i < n; i++)
    {
        int temp;
        scanf("%1d", &temp);
        if(temp == 1)
            a++;
        else
            b++;
    }
    int sum = fabs(a - b);
    printf("%d", sum);
    return 0;
}