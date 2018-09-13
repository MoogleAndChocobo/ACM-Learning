//~ #define LOCAL

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAX = 1e3 + 10;
const int INF = 0x3f3f3f3f;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define sfs(s) scanf("%s", s)
#define sfi(a) scanf("%d", &a)

int ans = 0;
int rec[MAX][MAX];

char getans(int i)
{
	if(rec[i]['A'] >= rec[i]['T'] && rec[i]['A'] >= rec[i]['G'] && rec[i]['A'] >= rec[i]['C'])
	{
		ans += rec[i]['T'] + rec[i]['G'] + rec[i]['C'];
		return 'A';
	}
	if(rec[i]['C'] >= rec[i]['T'] && rec[i]['C'] >= rec[i]['G'] && rec[i]['C'] >= rec[i]['A'])
	{
		ans += rec[i]['T'] + rec[i]['G'] + rec[i]['A'];
		return 'C';
	}
	if(rec[i]['G'] >= rec[i]['T'] && rec[i]['G'] >= rec[i]['A'] && rec[i]['G'] >= rec[i]['C'])
	{
		ans += rec[i]['T'] + rec[i]['A'] + rec[i]['C'];
		return 'G';
	}
	if(rec[i]['T'] >= rec[i]['A'] && rec[i]['T'] >= rec[i]['G'] && rec[i]['T'] >= rec[i]['C'])
	{
		ans += rec[i]['A'] + rec[i]['G'] + rec[i]['C'];
		return 'T';
	}
	return ' ';
}

int main()
{

#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	int T;
	while(~sfi(T))
	{
		while(T--)
		{
			int m, n;
			scanf("%d%d", &m, &n);
			mem(rec);
			ans = 0;
			rep(i, 0, m - 1)
			{
				char tmp[MAX] = {0};
				sfs(tmp);
				rep(j, 0, n - 1)
				{
					rec[j][(int)tmp[j]]++;
				}
			}
			rep(i, 0, n - 1)
			{
				putchar(getans(i));
			}
			putchar('\n');
			printf("%d\n", ans);
		}
	}
	return 0;
}