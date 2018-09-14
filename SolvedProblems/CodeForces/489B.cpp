#include<iostream>
#include<algorithm>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define mst(a) memset(a, 0, sizeof(a))

const int MAX = 1e2 + 10;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int boy[MAX] = {0};
    int girl[MAX] = {0};
    int m, n;
    cin >> n;
    FOR(i, 0, n - 1)
        cin >> boy[i];
    sort(boy, boy + n);
    cin >> m;
    FOR(i, 0, m - 1)
        cin >> girl[i];
    sort(girl, girl + m);

    int st = 0;
    int cnt1 = 0;
    FOR(i, 0, n - 1)
    {
        for(int j = st; j < m; j++)
        {
            if(girl[j] == boy[i] - 1 || girl[j] == boy[i] || girl[j] == boy[i] + 1)
            {
                cnt1++;
                st = j + 1;
                break;
            }
        }
    }

    int cnt2;
    cnt2 = st = 0;
    FOR(i, 0, m - 1)
    {
        for(int j = st; j < n; j++)
        {
            if(boy[j] == girl[i] - 1 || boy[j] == girl[i] || boy[j] == girl[i] + 1)
            {
                cnt2++;
                st = j + 1;
                break;
            }
        }
    }

    cout << max(cnt1, cnt2) << endl;
    return 0;
}