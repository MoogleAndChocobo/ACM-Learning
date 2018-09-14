#include<cstdio>
#include<algorithm>

using namespace std;

const int MAX = 105;

int main()
{
    int n;
    scanf("%d", &n);
    int s[MAX] = {0};
    for(int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    sort(s, s + n);
    for(int i = 0; i < n; i++)
    {
        printf("%d", s[i]);
        if(i != n - 1)
            printf(" ");
    }
    return 0;
}