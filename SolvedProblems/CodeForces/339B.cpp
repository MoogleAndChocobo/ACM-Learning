#include<cstdio>

int s[100010] = {0};

int main()
{
    int n, num;
    scanf("%d%d", &n, &num);
    for(int i = 0; i < num; i++)
        scanf("%d", &s[i]);
    long long times = s[0] - 1;
    for(int i = 1; i < num; i++)
    {
        if(s[i] > s[i - 1])
            times += s[i] - s[i - 1];
        else if(s[i] < s[i - 1])
            times += n - s[i - 1] + s[i];
    }
    printf("%lld\n", times);
    return 0;
}