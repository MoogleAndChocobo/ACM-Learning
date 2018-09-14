#include<cstdio>
#include<set>

using namespace std;

set<int> ans;

int main()
{
    int t;
    for(int i = 0; i < 4; i++)
    {
        scanf("%d", &t);
        ans.insert(t);
    }
    printf("%d\n", 4 - ans.size());
    return 0;
}