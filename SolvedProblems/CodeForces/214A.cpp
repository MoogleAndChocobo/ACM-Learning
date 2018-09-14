#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int cnt = 0;
    for(int i = 0; i <= min(n, m); i++)
    {
        int a = i;
        int b = n - a * a;
        if(a >= 0 && b >= 0 && a + b * b == m)
            cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}