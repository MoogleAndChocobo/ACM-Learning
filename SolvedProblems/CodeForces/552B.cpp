#include<iostream>
#include<string>
#include<sstream>
#include<cmath>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)

typedef long long LL;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string temp;
    while(cin >> temp)
    {
        int len = temp.size();
        LL n;
        stringstream ss(temp);
        ss >> n;
        if(len == 1)
            cout << n << endl;
        else
        {
            LL sum = 0;
            LL m = 1;
            FOR(i, 1, len - 1)
            {
                sum += 9 * m * i;
                m *= 10;
            }
            string s;
            FOR(i, 1, len - 1)
                s += '9';
            stringstream line(s);
            LL get;
            line >> get;
            sum += len * (n - get);
            cout << sum << endl;
        }
    }
    return 0;
}