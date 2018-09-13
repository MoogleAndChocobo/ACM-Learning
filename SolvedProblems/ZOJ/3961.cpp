#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define sfi(a) scanf("%d", &a)

const int MAX = 1e3 + 5;

int l, r;

struct Node
{
    int l, r;
    Node(int ll = 0, int rr = 0):l(ll), r(rr){}
    friend bool operator <(Node a, Node b)
    {
        if(a.l != b.l)
			return a.l < b.l;
		return a.r < b.r;
    }
};

bool insect(Node p, Node q)
{
    if(!(p < q))
	{
        Node tmp = p;
		p = q;
		q = tmp;
	}
	return p.r >= q.l;
}

bool gtinsect(Node p, Node q)
{
    if(!insect(p, q))
		return false;
    int s[100];
    s[0] = p.l, s[1] = p.r, s[2] = q.l, s[3] = q.r;
    sort(s, s + 4);
    l = s[1], r = s[2];
    return true;
}

int main()
{

	int T;
	sfi(T);
	while(T--)
	{
        int n, m, x, y;
        scanf("%d%d%d%d", &n, &m, &x, &y);

        Node a[MAX], b[MAX];
        vector<Node> ansa, ansb;

        rep(i, 1, x)
        	scanf("%d%d", &a[i].l, &a[i].r);
        rep(i, 1, y)
        	scanf("%d%d", &b[i].l, &b[i].r);
		sort(a + 1, a + x + 1);
		sort(b + 1, b + y + 1);

        Node pre = a[1];
        rep(i, 2, x)
        {
            if(insect(pre, a[i]))
				pre = Node(min(pre.l, a[i].l), max(pre.r, a[i].r));
			else
			{
				ansa.push_back(pre);
				pre = a[i];
			}
        }
        ansa.push_back(pre);

        pre = b[1];
        rep(i, 2, y)
        {
            if(insect(pre, b[i]))
				pre = Node(min(pre.l, b[i].l), max(pre.r, b[i].r));
			else
			{
				ansb.push_back(pre);
				pre = b[i];
			}
        }
        ansb.push_back(pre);

        int la = ansa.size(), lb = ansb.size();

        /*
        putchar('\n');
        rep(i, 0, la - 1)
        {
            printf("a : %d %d\n", ansa[i].l, ansa[i].r);
        }
        putchar('\n');
        rep(i, 0, lb - 1)
        {
            printf("b : %d %d\n", ansb[i].l, ansb[i].r);
        }
        */


        LL ans = 0;
        rep(i, 0, la - 1)
        {
            rep(j, 0, lb - 1)
            {
                if(!gtinsect(ansa[i], ansb[j]))
					continue;
				if(r - l + 1 >= m)
                    ans += (LL)(r - l + 2 - m);
            }
        }
        printf("%lld\n", ans);
	}
    return 0;
}