#include<cstdio>
#include<algorithm>

using namespace std;

const int MAX = 5005;

int cnt1 = 0, cnt2 = 0, cnt3 = 0;
int set1[MAX] = {0}, set2[MAX] = {0}, set3[MAX] = {0};

int main()
{
    int num;
    scanf("%d", &num);
    int m, n, o;
    m = n = o = 0;
    for(int i = 1; i <= num; i++)
    {
        int temp;
        scanf("%d", &temp);
        if(temp == 1)
        {
            cnt1++;
            set1[m] = i;
            m++;
        }
        else if(temp == 2)
        {
            cnt2++;
            set2[n] = i;
            n++;
        }
        else if(temp == 3)
        {
            cnt3++;
            set3[o] = i;
            o++;
        }
    }
    int mn = min(cnt1, cnt2);
    mn = min(mn, cnt3);
    printf("%d\n", mn);
    if(mn != 0)
        for(int i = 0; i < mn; i++)
            printf("%d %d %d\n", set1[i], set2[i], set3[i]);
    return 0;
}