#include<cstdio>
#include<set>

using namespace std;

int main()
{
    set<char> s;
    char c;
    while(scanf("%c", &c) == 1 && c != '\n')
        s.insert(c);
    if(s.size() % 2)
        printf("IGNORE HIM!\n");
    else
        printf("CHAT WITH HER!\n");
    return 0;
}