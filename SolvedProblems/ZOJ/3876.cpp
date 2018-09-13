#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
         //1
const int b[10]={6,9,6,5,5,5,5};

int cl(int y,int m=5,int d=1)
{
	int c=y/100;
	y=y%100;
	int w=y+y/4+c/4-2*c+26*(m+1)/10+d-1;
	w=(w%7+7)%7;
	return w;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
	{
		int a;
		scanf("%d",&a);
		printf("%d\n",b[cl(a)]);
	}
}