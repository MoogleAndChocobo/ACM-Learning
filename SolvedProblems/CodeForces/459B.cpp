#include<cstdio>
#include<algorithm>

using namespace std;

const int MAX = 200010;
int s[MAX] = {0};

int main()
{
    long long n;
    scanf("%lld", &n);
    for(long long i = 0; i < n; i++)
        scanf("%d", &s[i]);
    sort(s, s + n);
    if(s[n - 1] == s[0])
    {
        printf("0 %lld\n", n * (n - 1) / 2);
        return 0;
    }
    long long cnt_st = 1;
    for(int i = 1; i < n; i++)
        if(s[i] == s[0])
            cnt_st++;
        else
            break;
    long long cnt_en = 1;
    for(int i = n - 2; i >= 0; i--)
        if(s[i] == s[n - 1])
            cnt_en++;
        else
            break;
    printf("%d %lld\n", s[n - 1] - s[0], cnt_st * cnt_en);
    return 0;
}