#include<cstdio>

int main()
{
    int k, r;
    scanf("%d%d", &k, &r);
    bool flag = false;
    int i = 1;
    while(!flag)
    {
        if((i * k) % 10 <= r && (i * k) % 10 % r == 0)
        {
            printf("%d", i);
            flag = true;
        }
        i++;
    }
    return 0;
}