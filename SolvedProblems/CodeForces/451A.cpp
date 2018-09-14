#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int temp = min(m, n);
    if(temp % 2)
        printf("Akshat\n");
    else
        printf("Malvika\n");
    return 0;
}