#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAX = 105;

bool judge(char c)
{
    if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y')
        return true;
    return false;
}

int main()
{
    char s[MAX] = {0};
    scanf("%s", &s);
    int st = -1;
    int mx = 0;
    for(int i = 0; i <= strlen(s); i++)
    {
        if(i == strlen(s))
        {
            mx = max(mx, i - st);
            break;
        }
        if(judge(s[i]))
        {
            mx = max(mx, i - st);
            st = i;
        }
    }
    printf("%d", mx);
    return 0;
}