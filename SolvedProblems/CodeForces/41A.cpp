#include<cstdio>
#include<cstring>

typedef long long LL;

const int MAX = 1e2 + 10;

int main()
{
	char a[MAX], b[MAX];
	while(~scanf("%s%s", a, b))
	{
		int len = strlen(a);
		if(len != strlen(b))
		{
			printf("NO\n");
			continue;
		}
		bool flag = true;
		for(int i = 0, j = len - 1; i < len; i++, j--)
		{
			if(a[i] != b[j])
			{
				flag = false;
				break;
			}
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}