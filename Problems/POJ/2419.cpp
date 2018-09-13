#include<set>
#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)

const int MAXN = 1e2 + 10;

int main()
{
	int sumpeople, sumtrees;
	scanf("%d%d", &sumpeople, &sumtrees);
	string store[MAXN];
	FOR(i, 0, sumpeople)
		store[i] = "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
	int person, tree;
	while(~scanf("%d%d", &person, &tree))
	{
		store[person][tree] = '1';
	}
	set<string> ans;
	FOR(i, 1, sumpeople)
		ans.insert(store[i]);
	printf("%d\n", ans.size());
	return 0;
}