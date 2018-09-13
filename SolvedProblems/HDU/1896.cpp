#include<bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)

struct Node
{
    int meet;
    int dist;
    friend bool operator< (Node a, Node b)
    {
        if(a.meet < b.meet)
            return false;
        else if(a.meet == b.meet)
        {
            if(a.dist < b.dist)
                return false;
            else
                return true;
        }
        else
            return true;
    }
};

int main()
{
    int test;
    while(~scanf("%d", &test))
    {
        while(test--)
        {
            priority_queue<Node> pq;
            int n;
            scanf("%d", &n);
            FOR(i, 0, n - 1)
            {
                Node tempdata;
                scanf("%d%d", &tempdata.meet, &tempdata.dist);
                pq.push(tempdata);
            }
            int cnt = 0;
            int mxdist = 0;
            while(!pq.empty())
            {
                Node tempdata = pq.top();
                pq.pop();
                mxdist = tempdata.meet;
                if((++cnt) % 2)
                {
                    tempdata.meet += tempdata.dist;
                    pq.push(tempdata);
                }
            }
            printf("%d\n", mxdist);
        }
    }
    return 0;
}