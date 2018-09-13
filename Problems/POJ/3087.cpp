//没有输出0的情况。。

#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)

const int MAX = 1e2 + 10;

int main()
{
	int test;
	scanf("%d", &test);
	FOR(i, 1, test)
	{
		int len;
		scanf("%d", &len);
		char tmpa[MAX], tmpb[MAX], tmpneed[MAX * 2];
		scanf("%s%s%s", tmpa, tmpb, tmpneed);
		string a = tmpa, b = tmpb, need = tmpneed;
		int ans = 1;
		string tmp;
		for(int j = 0; j < len; j++)
		{
			tmp += b[j];
			tmp	+= a[j]; 
		}
		string org = tmp;
		while(tmp != need)
		{
			ans++;
			a.clear();
			b.clear();
			for(int j = 0; j < len; j++)
			{
				a += tmp[j];
				b += tmp[j + len];
			}
			tmp.clear();
			for(int j = 0; j < len; j++)
			{
				tmp += b[j];
				tmp	+= a[j]; 
			}
			if(tmp == org)
			{
				ans = -1;
				break;
			}
		}
		printf("%d %d\n", i, ans);
	}
	return 0;
}