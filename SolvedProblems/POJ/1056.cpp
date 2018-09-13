#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define sfd(a) scanf("%lf", &a)
#define push_back(a) pb(a)
#define sync ios::sync_with_stdio(0); cin.tie(0);

const int MAX = 15;
const int N = 1e5;

struct Tree
{
	int child[55][55 * 2 + 50];
	char BASE;
	
	Tree()
	{
		rep(i, 0, 55 - 1)
			mem(child);
		BASE = '0';
	}
	bool insert(string s)
	{
		int len = s.size();
		int now = 0;
		rep(i, 0, len - 1)
		{
			if(s[i] == '1')
				now = now * 2 + 1;
			else
				now *= 2;
			child[i][now]++;
		}
		if(child[len - 1][now] > 1)
			return false;
		return true;
	}
};

bool cmp(string a, string b)
{	
	return a.size() > b. size();	
}

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
	//~ freopen("out.txt", "w", stdout);
#endif

	sync

	string s;
	int kase = 0;
	while(cin >> s)
	{
		if(s == "9")
		{
			printf("Set %d is immediately decodable\n", ++kase);
			continue;
		}
		int cnt = 1;
		Tree tree;
		string store[1050];
		store[cnt] = s;
		while(cin >> s && s != "9")
		{
			store[++cnt] = s;
		}
		sort(store + 1, store + cnt + 1, cmp);
		bool flag = true;
		rep(i, 1, cnt)
		{
			if(!tree.insert(store[i]))
			{
				flag = false;
				break;
			}
		}
		printf("Set %d is%simmediately decodable\n", ++kase, flag ? " " : " not ");
	}
	return 0;
}