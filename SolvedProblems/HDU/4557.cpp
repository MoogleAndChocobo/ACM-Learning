#include<bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)

const int MAX = 20;

struct Person
{
    char name[MAX];
    int ability;
    int num;
    friend bool operator< (Person a, Person b)
    {
        if(a.ability > b.ability)
            return true;
        else if(a.ability == b.ability)
        {
            if(a.num > b.num)
                return true;
            else
                return false;
        }
        else
            return false;
    }
};

int main()
{
    int test;
    while(~scanf("%d", &test))
    {
        FOR(i, 1, test)
        {
            printf("Case #%d:\n", i);
            priority_queue<Person> pq;
            int n;
            scanf("%d", &n);
            int num = 0;
            while(n--)
            {
                char opr[MAX] = {0};
                scanf("%s", opr);
                if(!strcmp(opr, "Add"))
                {
                    Person tempdata;
                    scanf("%s%d", &tempdata.name, &tempdata.ability);
                    tempdata.num = ++num;
                    pq.push(tempdata);
                    printf("%d\n", pq.size());
                }
                else if(!strcmp(opr, "Find"))
                {
                    int lmt;
                    scanf("%d", &lmt);
                    priority_queue<Person> temppq;
                    Person tempdata;
                    bool flag = false;
                    while(!flag && !pq.empty())
                    {
                        tempdata = pq.top();
                        pq.pop();
                        if(tempdata.ability >= lmt)
                        {
                            flag = true;
                            printf("%s\n", tempdata.name);
                            break;
                        }
                        else
                            temppq.push(tempdata);
                    }
                    while(!temppq.empty())
                    {
                        pq.push(temppq.top());
                        temppq.pop();
                    }
                    if(!flag)
                        printf("WAIT...\n");
                }
            }
        }
    }

    return 0;
}