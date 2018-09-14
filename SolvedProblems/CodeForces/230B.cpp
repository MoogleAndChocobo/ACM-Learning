#include<cstdio>
#include<cmath>

bool isprime(int judge)
{
    if(judge == 1)
        return false;
    for(int i = 2; i < sqrt(judge) + 0.5; i++)
        if(judge % i == 0)
            return false;
    return true;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        long long temp;
        scanf("%lld", &temp);
        long long judge = sqrt(temp);
        if(judge * judge != temp)
        {
            printf("NO\n");
            continue;
        }
        if(isprime(judge))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}