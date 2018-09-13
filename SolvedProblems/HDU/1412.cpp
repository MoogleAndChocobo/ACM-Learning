#include<bits/stdc++.h>

using namespace std;

int main()
{
    int numa, numb;
    while(~scanf("%d%d", &numa, &numb))
    {
        set<int> ans;
        int sum = numa + numb;
        while(sum--)
        {
            int temp;
            scanf("%d", &temp);
            ans.insert(temp);
        }
        int cnt = 1, len = ans.size();
        for(set<int>::iterator it = ans.begin(); it != ans.end(); it++, cnt++)
        {
            printf("%d", *it);
            if(cnt != len)
                printf(" ");
            else
                printf("\n");
        }
    }
    return 0;
}