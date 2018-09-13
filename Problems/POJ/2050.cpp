#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>

using namespace std;

const int MAX = 1e2 + 10;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define pb(a) push_back(a)
#define mst(a, b) memset(a, b, sizeof(a))

int t;
char after[MAX][MAX][MAX];
char org[MAX][MAX][MAX];
char a[MAX], b[MAX], c[MAX];
int getlen[MAX];

struct Node
{
	int x, y;
	Node(int xx = 0, int yy = 0):x(xx), y(yy){}
	friend bool operator ==(Node a, Node b)
	{
		return a.x == b.x && a.y == b.y;
	}
	friend bool operator <(Node a, Node b)
	{
		if(a.x != b.x)
			return a.x < b.x;
		return a.y < b.y;
	}
};

map<string, vector<Node> > mp;

void operate(void)
{
	rep(i, 1, t)
	{
		rep(j, 1, getlen[i])
		{
			int len = strlen(org[i][j]);
			rep(k, 0, len - 1)
			{
				if(isupper(org[i][j][k]))
					after[i][j][k] = tolower(after[i][j][k]);
				else if(!isalpha(org[i][j][k]))
					after[i][j][k] = ' ';
			}
		}
	}
}

int check(char s[], int len)
{
	rep(i, 0, len - 1)
	{
		if(s[i] == 'A')
			return 1;
		if(s[i] == 'O')
			return 2;
		if(s[i] == 'N')
			return 3;
	}
	return 0;
}

void findand(void)
{
	string m = a, n = b;
	int lena = mp[m].size(), lenb = mp[n].size();
	set<int> judge;
	set<int> store;
	rep(i, 0, lena - 1)
	{
		judge.insert(mp[m][i].x);
	}
	rep(i, 0, lenb - 1)
	{
		if(judge.find(mp[n][i].x) != judge.end())
		{
			store.insert(mp[n][i].x);
		}
	}

	vector<int> ans[MAX];
	rep(i, 0, lena - 1)
	{
		if(store.find(mp[m][i].x) != store.end())
			ans[mp[m][i].x].pb(mp[m][i].y);
	}
	rep(i, 0, lenb - 1)
	{
		if(store.find(mp[n][i].x) != store.end())
		{
			ans[mp[n][i].x].pb(mp[n][i].y);
		}
	}

	rep(i, 1, t)
		sort(ans[i].begin(), ans[i].end());

	bool emmmm[MAX][MAX] = {0};
	bool sum = false;
	rep(i, 1, t)
	{
		int len = ans[i].size();
		if(sum && len)
		{
			puts("----------");
		}
		rep(j, 0, len - 1)
		{
			if(!emmmm[i][ans[i][j]])
			{
				puts(org[i][ans[i][j]]);
				emmmm[i][ans[i][j]] = true;
			}
			sum = true;
		}
	}
	if(!sum)
	{
		puts("Sorry, I found nothing.");
	}
}

void findor(void)
{
	string m = a, n = b;
	int lena = mp[m].size(), lenb = mp[n].size();
	set<Node> store;
	rep(i, 0, lena - 1)
	{
		store.insert(mp[m][i]);
	}
	rep(i, 0, lenb - 1)
	{
		store.insert(mp[n][i]);
	}

	vector<int> ans[MAX];
	for(set<Node>::iterator it = store.begin(); it != store.end(); it++)
	{
		ans[it->x].pb(it->y);
	}


	bool judge[MAX][MAX] = {0};
	bool sum = false;
	bool f = false;
	rep(i, 1, t)
	{
		int len = ans[i].size();
		if(f && len)
		{
			puts("----------");
		}
		rep(j, 0, len - 1)
		{
			if(!judge[i][ans[i][j]])
			{
				puts(org[i][ans[i][j]]);
				judge[i][ans[i][j]] = true;
			}
			f = true;
			sum = true;
		}
	}
	if(!sum)
	{
		puts("Sorry, I found nothing.");
	}
}

void findnot(void)
{
	string m = a;
	int len = mp[m].size();
	bool ans[MAX][MAX] = {0};
	bool judge[MAX] = {0};
	rep(i, 0, len - 1)
	{
		ans[mp[m][i].x][mp[m][i].y] = true;
		judge[mp[m][i].x] = true;
	}

	bool sum = false;
	bool flag = false;
	rep(i, 1, t)
	{
		if(judge[i])
			continue;
		if(!flag)
			flag = true;
		else
			puts("----------");
		rep(j, 1, getlen[i])
		{
			if(!ans[i][j])
			{
				puts(org[i][j]);
				sum = true;
			}
		}
	}
	if(!sum)
		puts("Sorry, I found nothing.");
}

void findord(void)
{
	string m = a;
	int len = mp[m].size();
	vector<int> ans[MAX];
	rep(i, 0, len - 1)
	{
		ans[mp[m][i].x].pb(mp[m][i].y);
	}

	bool judge[MAX][MAX] = {0};

	bool sum = false;
	bool f = false;
	rep(i, 1, t)
	{
		int len = ans[i].size();
		if(len == 0)
			continue;
		if(!f)
			f = true;
		else
			puts("----------");
		rep(j, 0, len - 1)
		{
			if(!judge[i][ans[i][j]])
			{
				puts(org[i][ans[i][j]]);
				judge[i][ans[i][j]] = true;
			}
			f = true;
			sum = true;
		}
	}
	if(!sum)
	{
		puts("Sorry, I found nothing.");
	}
}

void solve(void)
{
	rep(i, 1, t)
	{
		rep(j, 1, getlen[i])
		{
			int cnt = 0;
			char cur[MAX];
			int len = strlen(after[i][j]);
			rep(k, 0, len)
			{
				if(isalpha(after[i][j][k]))
				{
					cur[cnt++] = after[i][j][k];
				}
				else if(cnt != 0)
				{
					cur[cnt] = '\0';
					mp[cur].pb(Node(i, j));
					cnt = 0;
				}
			}
			
		}
	}
}

int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	sfi(t);
	getchar();
	rep(i, 1, t)
	{
		char tmp[MAX];
		int cnt = 0;
		while(gets(tmp) != NULL && strcmp(tmp, "**********"))
		{
			cnt++;
			strcpy(org[i][cnt], tmp);
			strcpy(after[i][cnt], tmp);
		}
		getlen[i] = cnt;
	}

	operate();
	solve();
	
	int ques;
	sfi(ques);
	getchar();
	rep(i, 1, ques)
	{
		char tmp[MAX];
		gets(tmp);
		int now = check(tmp, strlen(tmp));
		if(now == 1)
		{
			sscanf(tmp, "%s%s%s", a, c, b);
			findand();
		}
		else if(now == 2)
		{
			sscanf(tmp, "%s%s%s", a, c, b);
			findor();
		}
		else if(now == 3)
		{
			sscanf(tmp, "%s%s", b, a);
			findnot();
		}
		else
		{
			strcpy(a, tmp);
			findord();
		}
		puts("==========");
	}
	return 0;
}