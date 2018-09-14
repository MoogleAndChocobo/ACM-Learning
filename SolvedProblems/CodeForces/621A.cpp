#include<cstdio>
#include<algorithm>

using namespace std;

const int MAX = 100010;

int s[MAX] = {0};

int main()
{
    int n;
    scanf("%d", &n);
    long long sum = 0;
    int len = 0;
    for(int i = 0, j = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        if(num % 2 == 0)
            sum += num;
        else
        {
            s[j++] = num;
            len = j;
        }
    }
    sort(s, s + len);
    int i;
    if(len % 2)
        i = 1;
    else
        i = 0;
    for(int j = i; j < len; j++)
        sum += s[j];
    printf("%lld", sum);
    return 0;
}