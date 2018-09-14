#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<iostream>

using namespace std;

vector<string> l_first;
vector<string> l_second;
vector<string> ans;

int main()
{
    int num, test;
    scanf("%d%d", &num, &test);
    for(int i = 0; i < test; i++)
    {
        char s[15] = {0}, s1[15] = {0};
        scanf("%s%s", s, s1);
        string temp = s, temp1 = s1;
        l_first.push_back(temp);
        l_second.push_back(temp1);
    }
    for(int i = 0; i < num; i++)
    {
        char s[15] = {0};
        scanf("%s", s);
        string temp = s;
        for(int j = 0; j < l_first.size(); j++)
        {
            if(l_first[j] == temp)
            {
                if(l_first[j].size() <= l_second[j].size())
                    ans.push_back(l_first[j]);
                else
                    ans.push_back(l_second[j]);
            }
        }
    }
    int i = 0;
    for(vector<string>::iterator it = ans.begin(); it != ans.end(); it++, i++)
    {
        cout << *it;
        if(i != ans.size() - 1)
            printf(" ");
    }
    return 0;
}