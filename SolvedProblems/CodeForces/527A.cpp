#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    long long a, b;
    scanf("%lld%lld", &a, &b);
    if(a % b == 0)
        printf("%lld\n", a / b);
    else
    {
        long long cnt = 0;
        while(a != 0)
        {
            if(a < b)
                swap(a, b);
            cnt += a / b;
            a %= b;
        }
        printf("%lld\n", cnt);
    }
    return 0;
}