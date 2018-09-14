#include<cstdio>

int main()
{
    char c;
    int judge[5] = {0};
    while(scanf("%c", &c) == 1 && c != '\n')
    {
        if(c == 'h' && judge[0] == 0 && judge[1] == 0 && judge[2] == 0 && judge[3] == 0 && judge[4] == 0)
            judge[0] = 1;
        else if(c == 'e' && judge[0] == 1 && judge[1] == 0 && judge[2] == 0 && judge[3] == 0 && judge[4] == 0)
            judge[1] = 1;
        else if(c == 'l' && judge[0] == 1 && judge[1] == 1 && judge[2] == 0 && judge[3] == 0 && judge[4] == 0)
            judge[2] = 1;
        else if(c == 'l' && judge[0] == 1 && judge[1] == 1 && judge[2] == 1 && judge[3] == 0 && judge[4] == 0)
            judge[3] = 1;
        else if(c == 'o' && judge[0] == 1 && judge[1] == 1 && judge[2] == 1 && judge[3] == 1 && judge[4] == 0)
            judge[4] = 1;
    }
    if(judge[4] == 1)
        printf("YES");
    else
        printf("NO");
    return 0;
}