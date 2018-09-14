#include<cstdio>
#include<string>

using namespace std;

int main()
{
    int num;
    scanf("%d", &num);
    char s[1005][10] = {0};
    bool flag = false;
    for(int i = 0; i < num; i++)
    {
        scanf("%s", s[i]);
        string temp = s[i];
        if(flag == false)
        {
            if(temp.find("OO") == -1)
                continue;
            else
            {
                flag = true;
                if(s[i][0] == 'O' && s[i][1] == 'O')
                {
                    s[i][0] = '+';
                    s[i][1] = '+';
                }
                else
                {
                    s[i][3] = '+';
                    s[i][4] = '+';
                }
            }
        }
    }
    if(flag)
    {
        printf("YES\n");
        for(int i = 0; i < num; i++)
            printf("%s\n", s[i]);
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}