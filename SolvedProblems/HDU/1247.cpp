#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<string> dict;
vector<string> ans;


const int MAX = 26;

struct TrieNode
{
    int len;
    TrieNode *next[MAX];
    TrieNode(int x):len(x)
    {
        for(int i = 0; i < MAX; i++)
            next[i] = NULL;
    }
};

void Insert(TrieNode* &root, string str)
{
    int len = str.size();
    int val;
    TrieNode *p = root;
    for(int i = 0; i < len; i++)
    {
        val = str[i] - 'a';
        if(p -> next[val] == NULL)
        {
            p -> next[val] = new TrieNode(0);
        }
        p = p -> next[val];
    }
    p -> len++;
}

bool Search(TrieNode* root, string str)
{
    if(root == NULL)
        return false;
    int len = str.size();
    TrieNode *p = root;
    int val;
    for(int i = 0; i < len; i++)
    {
        val = str[i] - 'a';
        if(p -> next[val] == NULL)
            return false;
        p = p -> next[val];
    }
    return p -> len > 0;
}

int main()
{
    TrieNode* root = new TrieNode(0);
    string buf;
    while(cin >> buf)
    {
        Insert(root, buf);
        dict.push_back(buf);
    }
    for(int i = 1; i < dict.size(); i++)
    {
        string s1;
        for(int j = 0; j < dict[i].size() - 1; j++)
        {
            s1.push_back(dict[i][j]);
            if(Search(root, s1))
            {
                string s2;
                int temp = 0;
                for(int m = j + 1; m < dict[i].size(); m++, temp++)
                    s2.push_back(dict[i][m]);
                if(Search(root, s2))
                {
                    ans.push_back(dict[i]);
                    break;
                }
            }
        }
    }
    for(vector<string>::iterator it = ans.begin(); it != ans.end(); it++)
        cout << *it << endl;
    return 0;
}