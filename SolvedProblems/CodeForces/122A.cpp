#include<cstdio>
#include<string>
#include<sstream>
#include<iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    bool flag = true;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] != '4' && s[i] != '7')
        {
            flag = false;
            break;
        }
    }
    if(flag)
    {
        printf("YES\n");
        return 0;
    }
    int n;
    stringstream ss(s);
    ss >> n;
    if( n % 4 == 0 || n % 7 == 0 || n % 47 == 0)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}