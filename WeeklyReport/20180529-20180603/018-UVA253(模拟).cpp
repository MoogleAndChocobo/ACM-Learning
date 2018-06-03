#include <bits/stdc++.h>

using namespace std;

#define pb(a) push_back(a)
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define sfs(a) scanf("%s", a)

const int MAX = 1e4 + 50;

void show(vector<int> vec)
{
	int len = vec.size();
	rep(i, 1, len - 1)
		printf("%c", vec[i]);
	putchar('\n');
}

void init(vector<int> &now)
{
	now.clear();
	now.pb(0);
}

void change(vector<vector<int> > &vec, vector<int> &s)
{
	vector<int> now;
	init(now), now.pb(s[1]), now.pb(s[2]), now.pb(s[3]), now.pb(s[4]),	now.pb(s[5]), now.pb(s[6]);
	vec.pb(now);
	init(now), now.pb(s[4]), now.pb(s[6]), now.pb(s[3]), now.pb(s[2]),	now.pb(s[5]), now.pb(s[1]);
	vec.pb(now);
	init(now), now.pb(s[2]), now.pb(s[1]), now.pb(s[3]), now.pb(s[6]),	now.pb(s[5]), now.pb(s[4]);
	vec.pb(now);  
	init(now), now.pb(s[6]), now.pb(s[4]), now.pb(s[3]), now.pb(s[1]),	now.pb(s[5]), now.pb(s[2]);
	vec.pb(now);
}

void gt(vector<vector<int> > &vec, vector<int> &s)
{
	vector<int> now;
	init(now), now.pb(s[1]), now.pb(s[2]), now.pb(s[3]), now.pb(s[4]),	now.pb(s[5]), now.pb(s[6]);
	change(vec, now);
	init(now), now.pb(s[1]), now.pb(s[2]), now.pb(s[4]), now.pb(s[5]),	now.pb(s[6]), now.pb(s[3]);
	change(vec, now);
	init(now), now.pb(s[1]), now.pb(s[2]), now.pb(s[5]), now.pb(s[6]),	now.pb(s[3]), now.pb(s[4]);
	change(vec, now);
	init(now), now.pb(s[1]), now.pb(s[2]), now.pb(s[6]), now.pb(s[3]),	now.pb(s[4]), now.pb(s[5]);
	change(vec, now);
	init(now), now.pb(s[5]), now.pb(s[3]), now.pb(s[1]), now.pb(s[4]),	now.pb(s[2]), now.pb(s[6]);
	change(vec, now);
	init(now), now.pb(s[5]), now.pb(s[3]), now.pb(s[2]), now.pb(s[6]),	now.pb(s[1]), now.pb(s[4]);
	change(vec, now);
}

int main()
{
	string s;
	while(cin >> s)
	{
		vector<vector<int> > va, vb;
		vector<int> a, b;
		a.pb(0), a.pb(s[0]), a.pb(s[5]), a.pb(s[1]), a.pb(s[3]), a.pb(s[4]), a.pb(s[2]);
		b.pb(0), b.pb(s[6]), b.pb(s[11]), b.pb(s[7]), b.pb(s[9]), b.pb(s[10]), b.pb(s[8]);
		
		gt(va, a);
		gt(vb, b);
		
		//~ puts(">>");
		//~ rep(i, 1, 24)
		//~ {
			//~ show(va[i]);
		//~ }
		
		bool f = false;
		rep(i, 0, 23) rep(j, 0, 23)
			if(va[i] == vb[j])
			{
				//~ show(va[i]), show(vb[j]);
				f = true;
				break;
			}
		puts(f ? "TRUE" : "FALSE");
	}
	
	return 0;
}
