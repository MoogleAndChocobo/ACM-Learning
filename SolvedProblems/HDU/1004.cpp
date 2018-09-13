#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e3 + 10;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin >> n)
    {
        if(n == 0)
            break;
        map<string, int> store;
        int mx = 1;
        string ans;
        while(n--)
        {
            string s;
            cin >> s;
            if(store.find(s) == store.end())
                store.insert(pair<string,int>(s, 1));
            else
                store[s]++;
            if(mx <= store[s])
            {
                mx = store[s];
                ans = s;
            }
        }
        cout << ans << endl;
    }
    return 0;
}