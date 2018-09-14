#include<cstdio>
#include<map>
#include<algorithm>

using namespace std;

map<int,int> ans;

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        ans[temp]++;
    }
    int mx = 1;
    for(map<int,int>::iterator it = ans.begin(); it != ans.end(); it++)
        mx = max(mx, it -> second);
    printf("%d %d\n", mx, ans.size());
    return 0;
}