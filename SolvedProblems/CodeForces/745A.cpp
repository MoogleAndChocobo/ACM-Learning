#include<bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)

int main()
{
    string ini;
    while(cin >> ini)
    {
        set<string> store;
        store.insert(ini);
        int cnt = 0;
        int len = ini.size();
        FOR(i, 1, len)
        {
            string ret;
            ret += ini[len - 1];
            FOR(i, 0, len - 2)
                ret += ini[i];
            store.insert(ret);
            ini = ret;
        }
        printf("%d\n", store.size());
    }
    return 0;
}