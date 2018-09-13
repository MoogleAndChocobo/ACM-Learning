#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
	int a, b, c, d, e, i;
	bool operator<(const node& k)const
	{
		if (e == k.e)
		{
			if (b == k.b)
			{
				if (c == k.c)
					return d < k.d;
				else
				{
					if (d == k.d)
						return a < k.a;
					else
						return d < k.d;
				}
			}
			else
				return b < k.b;
		}
		else
			return e > k.e;
	}
	node(){}
};

int n;
node v[2020];
int ans[2020];
int tt[10];


int main()
{
	int t, cnt;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		cnt = 0;
		for (int i = 1;i <= n; i++)
		{
			scanf("%d %d/%d/%d %d", &v[i].a, &v[i].b, &v[i].c, &v[i].d, &v[i].e);
			v[i].i = i;
			if (v[i].e > 0)
				++cnt;
		}
		sort(v + 1, v + 1 + n);
		tt[6] = cnt * 0.03, tt[5] = cnt * 0.07, tt[4] = cnt * 0.2, tt[3] = cnt * 0.3;
		tt[1] = n - cnt;
		tt[2] = n - tt[6] - tt[5] - tt[4] - tt[3] - tt[1];
		for (int i = 5; i >= 1; i--)
			tt[i] += tt[i + 1];
		for (int i = 1, j = 6; i <= n; i++)
		{
			while (i > tt[j])
				--j;
			ans[v[i].i] = j;
		}
		for (int i = 1; i <= n; i++)
			printf("LV%d\n", ans[i]);
	}
	return 0;
}