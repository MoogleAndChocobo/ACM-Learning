#include<cstdio>
#include<algorithm>

using namespace std;

int gcd(int x, int y)
{
    if(x < y)
        swap(x, y);
    while(y)
    {
        int t = y;
        y = x % y;
        x = t;
    }
    return x;
}

int main()
{
    int a, b, n;
    scanf("%d%d%d", &a, &b, &n);
    while(n >= 0)
    {
        if(n < gcd(a, n))
        {
            printf("1\n");
            break;
        }
        n -= gcd(a, n);
        if(n < gcd(b, n))
        {
            printf("0\n");
            break;
        }
        n -= gcd(b, n);
    }
    return 0;
}