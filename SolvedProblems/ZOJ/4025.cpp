#include <bits/stdc++.h>

using namespace std;

#define sfi(a) scanf("%d", &a)
#define mem(a) memset(a, 0, sizeof(a))
#define rep(i, a, b) for(int i = a; i <= b; i++)

const int MAX = 1e5 + 5;
const int N = 1e6 + 5;

int s[MAX];
int plu[N], minu[N];

int main()
{
	int T;
	sfi(T);
	while(T--)
	{
		mem(plu), mem(minu);
        int n;
        sfi(n);
        rep(i, 1, n)
			sfi(s[i]);
		rep(i, 1, n)
		{
			int tmp;
			sfi(tmp);
            if(tmp >= s[i])
                plu[tmp - s[i]]++;
			else
                minu[s[i] - tmp]++;
		}
		int ans = 0;
		rep(i, 0, 200005)
			ans = max(ans, plu[i]), ans = max(ans, minu[i]);
		printf("%d\n", ans);
	}
    return 0;
}