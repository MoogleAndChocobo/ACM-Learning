#include<bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)

struct Card
{
	int h, w;
	bool flag;
};

bool cmp(Card a, Card b)
{
	if(a.h != b.h)
		return a.h < b.h;
	else if(a.w != b.w)
		return a.w < b.w;
	else
		return a.flag > b.flag;
}

const int MAX = 1e6 + 10;
Card s[MAX];
multiset<int> store;

int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		int n;
		scanf("%d", &n);
		store.clear();
		
		FOR(i, 0, n - 1)
		{
			scanf("%d%d", &s[i].h, &s[i].w);
			s[i].flag = 0;
		}
		FOR(i, n, 2 * n - 1)
		{
			scanf("%d%d", &s[i].h, &s[i].w);
			s[i].flag = 1;
		}
		sort(s, s + 2 * n, cmp);
		
		int ans = 0;
		FOR(i, 0, 2 * n - 1)
		{
			if(s[i].flag)
				store.insert(s[i].w);
			else
			{
				if(store.empty())
					continue;
				multiset<int>::iterator it = store.begin();
				if((*it) <= s[i].w)
				{
					it = store.lower_bound(s[i].w);
					it--;
					ans++;
					store.erase((*it));
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}