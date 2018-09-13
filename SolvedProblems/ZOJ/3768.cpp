#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define rep(i, a, b) for(int i = a; i <= b; i++)

int a [17777];

int init()
{
    for(int i=0;1;i++)
    {
        a[i]=(i+1)*i/2;
        if(a[i]>123456789)return i;
    }
}

int main()
{
    int k=init();

	int T;
    scanf("%d",&T);
    while(T--)
    {
       int n;
       scanf("%d",&n);
       int x1=lower_bound(a,a+k,n)-a;
       int x3=0;
       int x4=0;
       int x5=0;
       if(a[x1]==n)printf("%d\n",x1);
       else {
           for(int i=0;i<x1;i++)
           {
               int x2=lower_bound(a,a+x1,n-a[i])-a;
               if(a[i]+a[x2]==n){
                 printf("%d %d\n",i,x2);
                 goto N;
               }
               if(!x3)
               {
                   x3=lower_bound(a,a+x1,n-a[i]-a[x2-1])-a;
                    if(a[i]+a[x2-1]+a[x3]==n)x4=i,x5=x2-1;
                else x3=0;
               }
           }
           printf("%d %d %d\n",x5,x3,x4);
       }
       N:;
    }
	return 0;
}