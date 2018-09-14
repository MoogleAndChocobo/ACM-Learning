#include<cstdio>
#include<string>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)

int main()
{
    string s;
    FOR(i, 1, 500)
    {
        int x = i;
        if(x < 10)
        {
            char t = x + '0';
            s += t;
        }
        else if(x >= 10 && x <= 99)
        {
            char t = x / 10 + '0';
            s += t;
            t = x % 10 + '0';
            s += t;
        }
        else if(x >= 100 & x <= 500)
        {
            char t = x / 100 + '0';
            s += t;
            t = x / 10 % 10 + '0';
            s += t;
            t = x % 10 + '0';
            s += t;
        }
    }
    int n;
    while(~scanf("%d", &n))
    {
        printf("%c\n", s[n - 1]);
    }
    return 0;
}