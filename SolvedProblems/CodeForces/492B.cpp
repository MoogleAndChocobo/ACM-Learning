#include<cstdio>
#include<algorithm>

using namespace std;

const int MAX = 1005;

int main()
{
    int num;
    double emmm;
    scanf("%d%lf", &num, &emmm);
    double s[MAX] = {0};
    for(int i = 0; i < num; i++)
        scanf("%lf", &s[i]);
    s[num] = emmm;
    sort(s, s + num);
    double mymax = s[0] - 0;
    for(int i = 0; i < num - 1; i++)
    {
        if(s[i + 1] > emmm)
            break;
        if(mymax < (s[i + 1] - s[i]) / 2)
            mymax = (s[i + 1] - s[i]) / 2;
    }
    if(s[num] <= emmm && mymax < s[num] - s[num - 1])
        mymax = s[num] - s[num - 1];
    printf("%.10f", mymax);
    return 0;
}