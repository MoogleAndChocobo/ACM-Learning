#include<cstdio>
#include<algorithm>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)

const int MAX = 1e2 + 10;
int s[MAX][MAX] ={0};

int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int sum;
        scanf("%d", &sum);
        FOR(i, 0, sum - 1)
            for(int j = 0; j <= i; j++)
                scanf("%d", &s[i][j]);
        ROF(i, sum - 1, 1)
            for(int j = 0; j < i; j++)
                s[i - 1][j] += max(s[i][j], s[i][j + 1]);
        printf("%d\n", s[0][0]);
    }
    return 0;
}