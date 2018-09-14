#include<cstdio>
#include<algorithm>

using namespace std;

const int MAX = 105;

int main()
{
    int num;
    scanf("%d", &num);
    int s[MAX] = {0};
    int mx = 0;
    for(int i = 0; i < num; i++)
    {
        scanf("%d", &s[i]);
        mx = max(mx, s[i]);
    }
    int sum = 0;
    for(int i = 0; i < num; i++)
        sum += mx - s[i];
    printf("%d", sum);
    return 0;
}