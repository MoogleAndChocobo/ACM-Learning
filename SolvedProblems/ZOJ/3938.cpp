#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define sfd(a) scanf("%lf", &a)

const int MAX = 2e3 + 5;
const int N = 1e5 + 4;
const LL INIT = 0x3f3f3f3f3f3f3f3f;

int pic[10][10];
int opr[10];

struct Node
{
	int pos, lab;
	Node(int pp = 0, int bb = 0):pos(pp), lab(bb){}
} ans[MAX];

void init()
{
	mem(pic), mem(opr);
	mem(ans);
}


int findpos(int stage, int label)
{
	rep(i, 1, 4)
	{
		if(pic[stage][i] == label)
			return i;
	}
	return 1;
}

int main()
{
	int T;
	sfi(T);
	while(T--)
	{
		init();
		
		rep(i, 1, 5)
		{
			sfi(opr[i]);
			rep(j, 1, 4)
				sfi(pic[i][j]);
		}
		
		
		//stage 1
		if(opr[1] == 1 || opr[1] == 2)
			ans[1].pos = 2, ans[1].lab = pic[1][ans[1].pos];
		else if(opr[1] == 3)
			ans[1].pos = 3, ans[1].lab = pic[1][ans[1].pos];
		else
			ans[1].pos = 4, ans[1].lab = pic[1][ans[1].pos];
		
		//stage 2
		if(opr[2] == 1)
			ans[2].lab = 4, ans[2].pos = findpos(2, ans[2].lab);
		else if(opr[2] == 2 || opr[2] == 4)
			ans[2].pos = ans[1].pos, ans[2].lab = pic[2][ans[2].pos];
		else
			ans[2].pos = 1, ans[2].lab = pic[2][ans[2].pos];

		//stage 3
		if(opr[3] == 1)
			ans[3].lab = ans[2].lab, ans[3].pos = findpos(3, ans[3].lab);
		else if(opr[3] == 2)
			ans[3].lab = ans[1].lab, ans[3].pos = findpos(3, ans[3].lab);
		else if(opr[3] == 3)
			ans[3].pos = 3, ans[3].lab = pic[3][ans[3].pos];
		else
			ans[3].lab = 4, ans[3].pos = findpos(3, ans[3].lab);
		
		//stage 4
		if(opr[4] == 1)
			ans[4].pos = ans[1].pos, ans[4].lab = pic[4][ans[4].pos];
		else if(opr[4] == 2)
			ans[4].pos = 1, ans[4].lab = pic[4][ans[4].pos];
		else
			ans[4].pos = ans[2].pos, ans[4].lab = pic[4][ans[4].pos];
		
		//stage 5
		if(opr[5] == 1)
			ans[5].lab = ans[1].lab, ans[5].pos = findpos(5, ans[5].lab);
		else if(opr[5] == 2)
			ans[5].lab = ans[2].lab, ans[5].pos = findpos(5, ans[5].lab);
		else if(opr[5] == 3)
			ans[5].lab = ans[4].lab, ans[5].pos = findpos(5, ans[5].lab);
		else
			ans[5].lab = ans[3].lab, ans[5].pos = findpos(5, ans[5].lab);

		rep(i, 1, 5)
			printf("%d %d\n", ans[i].pos, ans[i].lab);
	}
	return 0;
}