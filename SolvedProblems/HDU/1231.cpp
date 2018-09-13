#include<bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)

const int MAX = 1e5 + 10;

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        if(n == 0)
            continue;
        int s[MAX] = {0};
        FOR(i, 0, n - 1)
            scanf("%d", &s[i]);
        int mx, tempmx;
        mx = tempmx = s[0];
        int st, en, tempst, tempen;
        st = en = tempst = tempen = 0;
        bool flag = true;
        FOR(i, 0, n - 1)
            if(s[i] >= 0)
            {
                flag = false;
                break;
            }
        if(flag)
        {
            printf("0 %d %d\n", s[0], s[n - 1]);
            continue;
        }
        FOR(i, 1, n - 1)
        {
            if(tempmx <= 0)
            {
                tempmx = s[i];
                tempst = i;
                tempen = i;
            }
            else
            {
                tempmx += s[i];
                tempen = i;
            }
            if(tempmx > mx)
            {
                mx = tempmx;
                tempen = i;
                st = tempst;
                en = tempen;
            }
        }
        printf("%d %d %d\n", mx, s[st], s[en]);
    }
    return 0;
}