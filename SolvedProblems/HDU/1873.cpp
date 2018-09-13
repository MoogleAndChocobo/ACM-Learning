#include<bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)

const int MAX = 10;

struct Node
{
    int pri;
    int num;
    friend bool operator< (Node a, Node b)
    {
        if(a.pri == b.pri)
            return a.num > b.num;
        else
            return a.pri < b.pri;
    }
};

int main()
{
    int test;
    while(~scanf("%d", &test))
    {
        priority_queue<Node> pq[MAX];
        int cnt = 0;
        while(test--)
        {
            char s[MAX] = {0};
            scanf("%s", s);
            if(!strcmp(s, "IN"))
            {
                int x, y;
                scanf("%d%d", &x, &y);
                Node temp;
                temp.num = ++cnt;
                temp.pri = y;
                pq[x].push(temp);
            }
            else if(!strcmp(s, "OUT"))
            {
                int x;
                scanf("%d", &x);
                if(pq[x].empty())
                    printf("EMPTY\n");
                else
                {
                    printf("%d\n", pq[x].top().num);
                    pq[x].pop();
                }
            }
        }
    }
    return 0;
}