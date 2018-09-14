#include<cstdio>
#include<cmath>

typedef long long LL;

const int MAX = 1e2;
int s[MAX] = {0};

int main()
{
    LL n, k;
    scanf("%lld%lld", &n, &k);
    LL temp = n;
    int cnt = 0;
    do
    {
        n >>= 1;
        cnt++;
    }while(n != 0);
    LL sum = 0;
    for(int i = 0; i < cnt; i++)
    {
        sum += pow(2, i);
    }
    if(k == 1)
        printf("%lld\n", temp);
    else
        printf("%lld\n", sum);
    return 0;
}