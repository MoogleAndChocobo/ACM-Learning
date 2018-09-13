#include<cstdio>
const char s[2][5]={"NO","YES"};
int main()
{
	int k,p;
	while(~scanf("%d %d",&k,&p))printf("%s\n",s[(k/(p-1))&1]);
}