#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int n, a, b;
    int sum = 0, temp = 1000;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d", &a, &b);
        temp = min(temp, b);
        sum += temp * a;
    }
    printf("%d\n", sum);
    return 0;
}