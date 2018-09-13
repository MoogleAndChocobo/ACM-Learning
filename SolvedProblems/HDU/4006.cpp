#include<bits/stdc++.h>

using namespace std;

const int MAX = 10;

int main()
{
    int times, num;
    while(~scanf("%d%d", &times, &num))
    {
        priority_queue<int, vector<int>, greater<int> > pq;
        while(times--)
        {
            char s[MAX] = {0};
            scanf("%s", s);
            if(!strcmp(s, "I"))
            {
                int tempdata;
                scanf("%d", &tempdata);
                pq.push(tempdata);
                if(pq.size() > num)
                    pq.pop();
            }
            else if(!strcmp(s, "Q"))
                printf("%d\n", pq.top());
        }
    }
    return 0;
}