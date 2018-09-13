#include<vector>
#include<cstdio>

using namespace std;

struct Node
{
    int client;
    int pri;
};

int main()
{
    vector<Node> store;
    int n;
    while(~scanf("%d", &n))
    {
        if(n == 0)
            break;
        else if(n == 1)
        {
            Node temp;
            scanf("%d%d", &temp.client, &temp.pri);
            store.push_back(temp);
        }
        else if(n == 2)
        {
            if(store.size())
            {
                int mxindex = 0;
                int len = store.size();
                for(int i = 1; i < len; i++)
                    if(store[mxindex].pri < store[i].pri)
                        mxindex = i;
                printf("%d\n", store[mxindex].client);
                vector<Node>::iterator it = store.begin();
                store.erase(it + mxindex);
            }
            else
                printf("0\n");
        }
        else if(n == 3)
        {
            if(store.size())
            {
                int mnindex = 0;
                int len = store.size();
                for(int i = 1; i < len; i++)
                    if(store[mnindex].pri > store[i].pri)
                        mnindex = i;
                printf("%d\n", store[mnindex].client);
                vector<Node>::iterator iter = store.begin();
                store.erase(iter + mnindex);
            }
            else
                printf("0\n");
        }
    }
    return 0;
}