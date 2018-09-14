#include<cstdio>
#include<algorithm>

using namespace std;

const int MAX = 55;

int main()
{
    int n, num;
    scanf("%d%d", &n, &num);
    int s[MAX] = {0};
    for(int i = 0; i < num; i++)
        scanf("%d", &s[i]);
    sort(s, s + num);
    int mn = s[num - 1] - s[num - n];
    for(int i = num - 1; i >= n - 1; i--)
        mn = min(mn, s[i] - s[i - n + 1]);
    printf("%d\n", mn);
    return 0;
}