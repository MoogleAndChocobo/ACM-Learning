#include<cstdio>

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        int temp = n / 7 * 2;
        int a = temp, b;
        if(n % 7 <= 2)
            b = temp + n % 7;
        else
        {
            b = temp + 2;
            if(n % 7 > 5)
                a += n % 7 - 5;
        }
        printf("%d %d\n", a, b);
    }
    return 0;
}