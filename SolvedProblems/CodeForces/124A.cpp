#include<cstdio>

int main()
{
    int sum, a, b;
    scanf("%d%d%d", &sum, &a, &b);
    int cnt = 0;
    for(int i = a; i + 1 <= sum; i++)
        if(sum - i - 1 <= b)
            cnt++;
    printf("%d\n", cnt);
    return 0;
}