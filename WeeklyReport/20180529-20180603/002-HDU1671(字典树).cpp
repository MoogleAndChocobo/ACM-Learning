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

const int MAX = 1e5 + 50;
const int N = 1e5;

struct Trie
{
	int tot, root, child[100050][30];
	char BASE;
	void init()
	{
		mem(child[1]);
		root = tot = 1;
		BASE = '0';
	}
	void insert(const char *str)
	{
		int *cur = &root;
		for (const char *p = str; *p; ++p)
		{
			cur = &child[*cur][*p-BASE];
			if (*cur == 0)
			{
				*cur = ++tot;
				mem(child[tot]);
			}
		}
	}
	bool query(const char *str)
	{
		int *cur = &root;
		for (const char *p = str; *p && *cur; ++p)
			cur = &child[*cur][*p - BASE];
		return *cur;
	}
} t;

bool cmp(char a[], char b[])
{
	return strlen(a) > strlen(b);
}

struct Node
{
	char v[15];
	int len;
	friend bool operator < (Node a, Node b)
	{
		return a.len > b.len;
	}
	
} s[10050];


int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
	//~ freopen("out.txt", "w", stdout);
#endif

	int kase;
	sfi(kase);
	while(kase--)
	{
		t.init();
		int n;
		sfi(n);
		rep(i, 1, n)
			sfs(s[i].v), s[i].len = strlen(s[i].v);
		sort(s + 1, s + n + 1);
		bool flag = true;
		rep(i, 1, n)
		{
			if(t.query(s[i].v))
			{
				flag = false;
				break;
			}
			t.insert(s[i].v);
		}
		puts(!flag ? "NO" : "YES");
	}
	
	return 0;
}
