#include<cstdio>
#include<string>
#include<cctype>

using namespace std;

const int MAX = 105;

int main()
{
    int num;
    scanf("%d", &num);
    getchar();
    char s[MAX] = {0};
    for(int i = 0; i < num; i++)
    {
        scanf("%c", &s[i]);
        s[i] = tolower(s[i]);
    }
    string ss = s;
    bool flag = true;
    for(int i = 'a'; i <= 'z'; i++)
    {
        if(ss.find(i) == -1)
        {
            flag = false;
            break;
        }
    }
    if(flag)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}