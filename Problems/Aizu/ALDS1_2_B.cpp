#include<cstdio>
#include<algorithm>
 
using namespace std;
 
#define FOR(i, a, b) for(int i = a; i <= b; i++)
 
const int MAX = 1e2 + 10;
int s[MAX];
 
int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        FOR(i, 0, n - 1)
            scanf("%d", &s[i]);
        int cnt = 0;
        FOR(i, 0, n - 1)
        {
            int minj = i;
            for(int j = i + 1; j < n; j++)
            {
                if(s[j] < s[minj])
                    minj = j;
            }
            if(minj != i)
            {
                swap(s[minj], s[i]);
                cnt++;
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