#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e2 + 10;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int test;
    while(cin >> test)
    {
        while(test--)
        {
            map<string,map<string,int> > store;
            int n;
            cin >> n;
            while(n--)
            {
                string fruit, city;
                int tempnum;
                cin >> fruit >> city >> tempnum;
                store[city][fruit] += tempnum;
            }
            for(map<string,map<string,int> >::iterator it = store.begin(); it != store.end(); it++)
            {
                cout << it->first << endl;
                for(map<string,int>::iterator iter = store[it->first].begin(); iter != store[it->first].end(); iter++)
                {
                    cout << "   |----" << iter->first << "(" << iter->second << ")" << endl;
                }
            }
            if(test)
                cout << endl;
        }
    }
    return 0;
}