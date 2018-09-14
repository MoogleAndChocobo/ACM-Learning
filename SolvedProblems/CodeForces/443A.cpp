#include<cstdio>
#include<set>

using namespace std;

int main()
{
    char c;
    set<char> s;
    while(scanf("%c", &c) == 1 && c != '\n')
    {
        if(c != '{' && c != '}' && c != ',' && c != ' ')
            s.insert(c);
    }
    printf("%d", s.size());
    return 0;
}