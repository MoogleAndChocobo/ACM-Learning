#include<cstdio>
#include<algorithm>

using namespace std;

const int MAX = 6;
int s[6] = {0};

int main()
{
    for(int i = 0; i < 6; i++)
        scanf("%d", &s[i]);
    sort(s, s + 6);
    int mxhere = 1, get = -1;
    bool flag = false;
    for(int i = 1; i < 6; i++)
    {
        if(s[i] == s[i - 1])
            mxhere++;
        else
            mxhere = 1;
        if(mxhere == 4)
        {
            flag = true;
            get = s[i];
            break;
        }
    }
    if(!flag)
    {
        printf("Alien\n");
        return 0;
    }
    for(int i = 0, j = 0; j != 4; i++)
    {
        if(s[i] == get)
        {
            s[i] = -1;
            j++;
        }
    }
    int a, b;
    for(int i = 0; i < 6; i++)
    {
        if(!flag)
            break;
        if(s[i] != -1)
        {
            a = s[i];
            for(int j = i + 1; j < 6; j++)
            {
                if(s[j] != -1)
                {
                    b = s[j];
                    flag = false;
                    break;
                }
            }
        }
    }
    if(a == b)
        printf("Elephant\n");
    else
        printf("Bear\n");
    return 0;
}