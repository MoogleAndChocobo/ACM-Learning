#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
ll eular(ll a)
{
	ll res = a;
	for (ll i = 2; i * i <= a; i++)
	{
		if (a % i == 0)
		{
			res -= res / i;
			while (a % i == 0)
				a /= i;
		}
	}
	if (a > 1)
		res -= res / a;
	return res;
}

bool cl(int year,int month,int day)
{
    if(month < 3) { year -= 1;  month += 12; }
    int c = int (year / 100), y = year - 100 * c;
    int w = int ( c / 4) - 2 * c + y + int ( y / 4 ) +(26 * ( month + 1 ) / 10) + day - 1;
    w = (w % 7 + 7) % 7;

    if (w == 1) return 1;
    else return 0;
}

struct node
{
	ll y;
	ll m;
	ll d;
	node(){}
	node(ll _y,ll _m,ll _d): y(_y), m(_m) ,d(_d){}
}e[2333];

ll init()
{
	ll cnt=0;
	for(ll i=1753;i<1753+400;i++)
	{
		for(ll j=1;j<=12;j++)
		{
			if(cl(i,j,1))e[cnt++]=node(i-1753,j,1);
			if(cl(i,j,11))e[cnt++]=node(i-1753,j,11);
			if(cl(i,j,21))e[cnt++]=node(i-1753,j,21);
		}
	}
	return cnt;
}

int main()
{
	ll c=init();
	int T=in();
	while(T--)
	{
		bool f=0;
		ll y=in(),m=in(),d=in(),n=in();
		while(n)
		{
			if(d>21)
			{
				d=1;
				m++;
			}
			if(m>12)
			{
				m=1;
				y++;
			}
			if((y-1753)%400==0&&m==1&&d==1)break;
			if(cl(y,m,d))
			{
				n--;
				if(!n){
					f=1;
					printf("%lld %lld %lld\n",y,m,d);
					break;
				}
			}
			d+=10;
		}
		if(f)continue;
		y+=n/c*400;
		n=n%c-1;
		if(n<0)
		{
			n+=c;
			y-=400;
		}
		node ans=node(y+e[n].y,e[n].m,e[n].d);
		printf("%lld %lld %lld\n",ans.y,ans.m,ans.d);
	}
	return 0;
}