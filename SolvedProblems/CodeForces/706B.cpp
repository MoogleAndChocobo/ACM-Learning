#include<cstdio>
#include<algorithm>

using namespace std;

const int MAX = 100010;
int s[MAX] = {0};

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    sort(s, s + n);
    int times;
    scanf("%d", &times);
    for(int i = 0; i < times; i++)
    {
        int temp;
        scanf("%d", &temp);
        int index = upper_bound(s, s + n, temp) - s;
        printf("%d\n", index);
    }
    return 0;
}