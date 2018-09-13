#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cctype>

using namespace std;

const int MAX = 1e2 + 10;

bool cmp(char a, char b)
{
	if((isupper(a) && isupper(b)) || (islower(a) && islower(b)))
		return a < b;
	else if((a - b == 32) || (b - a == 32))
		return a < b;
	else if(isupper(a) && islower(b))
		return a < (b - 32);
	else if(islower(a) && isupper(b))
		return (a - 32) < b;
	return false;
}

int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		char s[MAX] = {0};
		scanf("%s", s);
		int len = strlen(s);
		sort(s, s + len, cmp);
		//printf("%s\n\n", s);
		do
		{
			printf("%s\n", s);
		}while(next_permutation(s, s + len, cmp));
	}
	return 0;
}