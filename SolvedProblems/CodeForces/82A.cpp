#include<cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    int i = 1;
    for( ; n > 5 * i; i *= 2)
        n -= 5 * i;
    if(n % i)
        n = n / i + 1;
    else
        n /= i;
    switch(n)
    {
        case 1:
            printf("Sheldon\n");
            break;
        case 2:
            printf("Leonard\n");
            break;
        case 3:
            printf("Penny\n");
            break;
        case 4:
            printf("Rajesh\n");
            break;
        case 5:
            printf("Howard\n");
            break;
    }
    return 0;
}