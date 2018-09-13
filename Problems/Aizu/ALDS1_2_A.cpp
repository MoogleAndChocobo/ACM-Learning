#include<cstdio>
#include<algorithm>
 
using namespace std;
 
#define FOR(i, a, b) for(int i = a; i <= b; i++)
 
const int MAX = 1e2 + 10;
 
int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        int s[MAX] = {0};
        int cnt= 0;
        FOR(i, 0, n - 1)
            scanf("%d", &s[i]);
        FOR(i, 1, n - 1)
        {
            for(int j = n - 1; j >= i; j--)
            {
                if(s[j] < s[j - 1])
                {
                    cnt++;
                    swap(s[j], s[j - 1]);
                }
            }
        }
        FOR(i, 0, n - 1)
        {
            printf("%d", s[i]);
            if(i != n - 1)
                printf(" ");
            else
                printf("\n");
        }
        printf("%d\n", cnt);
    }
    return 0;
}