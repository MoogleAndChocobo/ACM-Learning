#include<cstdio>

#define FOR(i, a, b) for(int i = a; i <= b; i++)

const int MAX = 1e2 + 10;
int s[MAX], n;

void Print(void)
{
	FOR(i, 0, n - 1)
	{
		printf("%d", s[i]);
		if(i != n - 1)
			printf(" ");
		else
			printf("\n");
	}
	return;
}

int main()
{
	while(~scanf("%d", &n))
	{
		FOR(i, 0, n - 1)
			scanf("%d", &s[i]);
		Print();
		FOR(i, 1, n - 1)
		{
			int v = s[i];
			int j = i - 1;
			while(j >= 0 && s[j] > v)
			{
				s[j + 1] = s[j];
				j--;
			}
			s[j + 1] = v;
			Print();
		}
	}
	return 0;
}