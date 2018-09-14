#include<cstdio>
#include<algorithm>

using namespace std;

int lcm(int m, int n)
{
    int a = max(m, n), b = min(m, n);
    while(b)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return m / a * n;
}

int main()
{
    int n, m, z;
    while(~scanf("%d%d%d", &n, &m, &z))
    {
        printf("%d\n", z / lcm(n, m));
    }
    return 0;
}