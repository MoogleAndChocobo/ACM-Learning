#include<cstdio>
#include<set>

using namespace std;

set<int> ans;

int main()
{
    int mx = 0;
    scanf("%d", &mx);
    int num;
    for(int i = 0; i < 2; i++)
    {
        scanf("%d", &num);
        for(int j = 0; j < num; j++)
        {
            int temp;
            scanf("%d", &temp);
            if(temp >= 1 && temp <= mx)
                ans.insert(temp);
        }
    }
    if(ans.size() == mx)
        printf("I become the guy.\n");
    else
        printf("Oh, my keyboard!\n");
    return 0;
}