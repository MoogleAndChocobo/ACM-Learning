#include<cstdio>
#include<string>
#include<map>

using namespace std;

map<string, int> ans;

int main()
{
    int n;
    scanf("%d", &n);
    string temp;
    int num;
    char s[40] = {0};
    for(int  i = 0; i < n; i++)
    {
        scanf("%s", s);
        temp = s;
        if(ans.find(temp) == ans.end())
        {
            ans[temp] = 1;
            printf("OK\n");
        }
        else
            printf("%s%d\n", s, ans[temp]++);
    }
    return 0;
}