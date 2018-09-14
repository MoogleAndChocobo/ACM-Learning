#include<cstdio>
#include<algorithm>

using namespace std;

const int MAX = 2005;
int s[MAX] = {0};
int s1[MAX] = {0};
int ans[MAX] = {0};

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
        s1[i] = s[i];
    }
    sort(s1, s1 + n);
    for(int i = 0; i < n; i++)
    {

        for(int j = 0; j < n; j++)
        {
            if(s1[j] > s[i])
            {
                ans[i] = n - j;
                break;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d", ans[i] + 1);
        if(i != n - 1)
            printf(" ");
        else
            printf("\n");
    }
    return 0;
}