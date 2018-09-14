#include<cstdio>
#include<algorithm>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)

const int MAX = 1e5 + 10;

int main()
{
    int n;
    int s[MAX] = {0};
    while(~scanf("%d", &n))
    {
        FOR(i, 0, n - 1)
            scanf("%d", &s[i]);
        int mx = 1, tempmx = 1;
        FOR(i, 1, n - 1)
        {
            if(s[i] > s[i - 1])
                tempmx++;
            else
                tempmx = 1;
            mx = max(tempmx, mx);
        }
        printf("%d\n", mx);
    }
    return 0;
}