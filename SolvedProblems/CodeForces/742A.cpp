#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    if(n == 0)
    {
        printf("1\n");
        return 0;
    }
    if(n % 4 == 0)
        printf("6\n");
    else if(n % 4 == 1)
        printf("8\n");
    else if(n % 4 == 2)
        printf("4\n");
    else
        printf("2\n");
    return 0;
}