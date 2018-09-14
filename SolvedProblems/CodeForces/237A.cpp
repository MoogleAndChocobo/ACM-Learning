#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    int sum = 1;
    int tempsum = 1;
    scanf("%d", &n);
    int preh, prem, temph, tempm;
    scanf("%d%d", &preh, &prem);
    for(int i = 1; i < n; i++)
    {
        scanf("%d%d", &temph, &tempm);
        if(temph == preh && tempm == prem)
            tempsum++;
        else
            tempsum = 1;
        sum = max(tempsum, sum);
        preh = temph;
        prem = tempm;
    }
    printf("%d", sum);
    return 0;
}