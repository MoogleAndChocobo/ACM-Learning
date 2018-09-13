#include<cstdio>
#include<cctype>
#include<algorithm>

using namespace std;
typedef long long ll;
typedef long long LL;

#define sync ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fli freopen("in.txt", "r", stdin);
#define flo freopen("out.txt", "w", stdout);
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define sfs(a) scanf("%s", &a)

inline ll in()
{
	char c=getchar();
	while(!isdigit(c))c=getchar();
	ll x=0;
	while(isdigit(c))
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	long long n, m;
	while (scanf("%lld%lld", &n, &m) == 2)
	{
		ll c=min(n,m)/2016;
		ll a = min(n, m)%2016, b = max(n, m);
		ll ans = 0;
		for (ll i = 1; i <= 2016; i++)
			ans += b / (2016 / gcd(2016, i));
		ans*=c;
		for(ll i = 1;i<=a;i++)
			ans+=b/(2016/gcd(2016,i));
		printf("%lld\n", ans);
	}
	return 0;
}