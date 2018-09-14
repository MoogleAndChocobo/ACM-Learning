#include<cstdio>
#include<string>

using namespace std;

int main()
{
    char s[110] = {0};
    scanf("%s", s);
    string ss = s;
    if(ss.find("0000000") == -1 && ss.find("1111111") == -1)
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}