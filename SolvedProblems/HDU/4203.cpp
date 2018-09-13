#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int test;
    scanf("%d", &test);
    while(test--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        if(m % 2)
            printf("%d\n", n % 2);
        else
        {
            n %= m + 1;
            if(m == n)
                printf("%d\n", m);
            else
                printf("%d\n", n % 2);
        }
    }
    return 0;
}