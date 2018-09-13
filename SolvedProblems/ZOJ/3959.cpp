#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
        int n;
        scanf("%d", &n);
        int s[1005] = {0};
        for(int i = 1; i<= n; i++)
            scanf("%d", &s[i]);
        bool f = true;
        int cnt = 0, mn = 10000000;
        if(n < 10 || n > 13)
		{
            f = false;
            goto N;
		}
		sort(s + 1, s + n + 1);

		if(s[1] != 1)
		{
            f = false;
            goto N;
		}
		for(int i = 1; i < n - 1; i++)
		{
            if(s[i] == 1)
				cnt++;
			if(s[i + 1] - s[i] > 2)
			{
                f = false;
                goto N;
			}
		}
		if(s[n - 1] == 1)
			cnt++;
		if(s[n] == 1)
			cnt++;
		if(cnt < 2)
			f = false;

		N:;
		puts(f ? "Yes" : "No");
	}
    return 0;
}